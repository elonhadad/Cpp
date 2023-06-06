//
// Created by ELON HADAD on 05/01/2023.
//

#ifndef EX_04_QUEUE_H
#define EX_04_QUEUE_H

#include <iostream>
#include "Node.h"

using namespace std;

template<typename T>
class Queue {

public:
    Queue();                                    // default constructor.
    Queue(const Queue<T> &q);                   // copy constructor.
    Queue &operator=(const Queue<T> &q);        // copy assignment operator.
    ~Queue();                                   // destructor.

    /**
     * regular remove the head of the queue.
     */
    void dequeue();

    /**
     * remove the element from queue.
     * @param node - node to remove.
     */
    void dequeue(Node<T> *node);

    /**
     * insert element to queue regular insert.
     * @param data - the element to insert.
     */
    void enqueue(T data);

    /**
     * insert element to queue by priority.
     * using with operator <. you MUST to implement this op in your class.
     * @param data - the element to insert.
     */
    void enqueueSorted(T data);

    /**
     * checking if the queue is empty.
     * @return true if the queue is empty.
     */
    bool isEmpty() const;

    /**
     * queue clearing function
     * deleting all members, i.e. moving to an empty queue.
    */
    void cleanQueue();

    /**
     * queue sorting by priority
     * using with operator <. you MUST to implement this op in your class.
     */
    void sort_queue();

    /**
     * printing the queue
     * using with operator <<. you MUST to implement this op in your class.
     */
    void print();

    /**
     * A query about the number of members in the queue
     * @return integer of queue size.
     */
    int howMany();

    /**
     * look at the member at the top of the queue.
     * @return the first element in queue.
     */
    T first() const;

    //  Getters
    Node<T> *getHead() const;
    Node<T> *getTail() const;
    Node<T> *getCursor() const;

    //  Setters
    void setCursor(Node<T> *c);

private:
    Node<T> *head;
    Node<T> *tail;
    Node<T> *cursor;
    int size;
};

template<typename T>
Queue<T>::Queue() {
    head = nullptr;
    tail = nullptr;
    cursor = nullptr;
    size = 0;
}

template<typename T>
Queue<T>::Queue(const Queue<T> &q) {
    head = q.head;
    tail = q.tail;
    cursor = q.cursor;
    size = q.size;
}

template<typename T>
Queue<T> &Queue<T>::operator=(const Queue<T> &q) {
    if (this != &q) {
        head = q.head;
        tail = q.tail;
        cursor = q.cursor;
        size = q.size;
    }
    return *this;
}

template<typename T>
Queue<T>::~Queue() {
    cursor = head;
    for (int i = 0; i < size; i++) {
        Node<T> *temp = head;
        head = head->getNext();
        if (head == nullptr) {
            delete temp;
            return;
        }
        delete temp;
    }
}


template<typename T>
void Queue<T>::dequeue() {
    Node<T> *temp = head;
    head = head->getNext();
    if (head == nullptr)
        return;

    head->setPrev(nullptr);
    delete temp;
    if (head == nullptr)
        tail = nullptr;

    size--;
}

template<typename T>
void Queue<T>::dequeue(Node<T> *node) {
    if (node->getPrev() == nullptr) {
        dequeue();
        return;
    }
    node->getPrev()->setNext(node->getNext());
    node->getNext()->setPrev(node->getPrev());
    delete node;

    size--;

}

template<typename T>
void Queue<T>::enqueue(T data) {
    Node<T> *new_node = new Node<T>(data);
    if (tail != nullptr) {
        new_node->setPrev(tail);
        tail->setNext(new_node);
    }
    tail = new_node;
    if (head == nullptr)
        head = new_node;

    size++;
}

template<typename T>
void Queue<T>::enqueueSorted(T data) {
    Node<T> *new_node = new Node<T>(data);
    if (head == nullptr) {
        head = new_node;
        tail = new_node;
        size++;
        return;
    } else if (new_node->getData() < tail->getData()) {
        new_node->setPrev(tail);
        tail->setNext(new_node);
        tail = new_node;
    } else {
        cursor = tail;
        while (cursor->getPrev() != nullptr && cursor->getPrev()->getData() <= data)
            cursor = cursor->getPrev();

        if (cursor->getPrev() != nullptr) {
            cursor->getPrev()->setNext(new_node);
        }
        new_node->setPrev(cursor->getPrev());
        cursor->setPrev(new_node);
        new_node->setNext(cursor);
        if (new_node->getPrev() == nullptr) {
            head = new_node;
        }
    }
    size++;
}

template<typename T>
bool Queue<T>::isEmpty() const {
    return head == nullptr;
}

template<typename T>
void Queue<T>::cleanQueue() {
    cursor = head;
    for (int i = 0; i < size; i++) {
        Node<T> *temp = head;
        head = head->getNext();
        if (head == nullptr) {
            delete temp;
            return;
        }
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
    cursor = nullptr;
}

template<typename T>
void Queue<T>::sort_queue() {
    Queue<T> *temp = new Queue<T>;
    cursor = tail;
    while (cursor != nullptr) {
        temp->enqueueSorted(cursor->getData());
        cursor = cursor->getPrev();
    }
    *this = *temp;
}

template<typename T>
void Queue<T>::print() {
    sort_queue();
    cursor = tail;
    while (cursor != nullptr) {
        cout << cursor->getData();
        cursor = cursor->getPrev();
    }
}

template<typename T>
int Queue<T>::howMany() {
    return size;
}

template<typename T>
T Queue<T>::first() const {
    if (!isEmpty())
        return head->getData();
}

/**
 *  Getters
 */

template<typename T>
Node<T> *Queue<T>::getHead() const {
    return head;
}

template<typename T>
Node<T> *Queue<T>::getTail() const {
    return tail;
}

template<typename T>
Node<T> *Queue<T>::getCursor() const {
    return cursor;
}

/**
 *  Setters
 */

template<typename T>
void Queue<T>::setCursor(Node<T> *c) {
    Queue::cursor = c;
}

#endif //EX_04_QUEUE_H
