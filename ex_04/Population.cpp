//
// Created by ELON HADAD on 15/12/2022.
//

#include "Population.h"
#include "World.h"
#include <iostream>

Population::Population() {
    this->flag = false;
    this->queue = new Queue<Virus>();
}

Population::Population(const Population &p) {
    this->flag =p.flag;
    this->queue = p.queue;
}

Population &Population::operator=(const Population &p) {
    if (this != &p) {
        this->flag = p.flag;
        this->queue = p.queue;
    }
    return *this;
}

void Population::operator++(__attribute__((unused)) int x) {
    if (!flag) {
        queue->setCursor(queue->getHead());
        while (queue->getCursor()->getData().getName()[0] == 'P') {
            queue->setCursor(queue->getCursor()->getNext());
            if (queue->getCursor() == nullptr) {
                flag = true;
                return;
            }
        }
        Virus *first = new Virus(queue->getTail()->getData());
        queue->getTail()->getData().setVersion();
        first->setRealVer(*queue->getTail()->getData().getVersion());
        queue->dequeue(queue->getCursor());
        queue->enqueueSorted(*first);
    }
}

Population& Population::Individual_update() {
    Population *temp = new Population();
    queue->setCursor(queue->getTail());
    while (queue->getCursor() != nullptr) {
        *(*queue->getCursor()->getData());
        queue->setCursor(queue->getCursor()->getPrev());
    }
    queue->setCursor(queue->getHead());
    while (queue->getCursor() != nullptr){
        auto *v = new Virus(*queue->getCursor()->getData());
        v->setGrade();
        temp->queue->enqueueSorted(*v);
        queue->dequeue();
        queue->setCursor(queue->getHead());
    }
    *this = *temp;
    if(queue->getTail()->getData().getGrade() < World::best->getGrade())
        World::best = new Virus(queue->getTail()->getData());
    return *this;
}

Queue<Virus> *Population::getQueue() const {
    return queue;
}

Population::~Population() {
    delete queue;
}