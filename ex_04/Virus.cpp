//
// Created by ELON HADAD on 15/12/2022.
//

#include "Virus.h"
#include "World.h"
#include <iostream>

Virus::Virus() {
    this->pm = 0;
    this->counter = 0;
    this->real_ver = 0;
    this->version = nullptr;
    this->name = "";
    this->grade = 2;
    this->vector = new int[World::dim];
    for (int i = 0; i < World::dim; i++) {
        vector[i] = 0;
    }
}

Virus::Virus(string str,const int *arr) {
    this->pm = 0;
    this->counter = 0;
    this->version = &counter;
    this->real_ver = 0;
    this->name = str;
    this->grade = 2;
    this->vector = new int[World::dim];
    for (int i = 0; i < World::dim; i++) {
        vector[i] = (arr[i]);
    }
}

Virus::Virus(const Virus &v) {
    this->pm = v.pm;
    this->counter = v.counter;
    this->version = v.version;
    this->real_ver = v.real_ver;
    this->name = v.name;
    this->grade = v.grade;
    this->vector = new int[World::dim];
    for (int i = 0; i < 10; i++) {
        vector[i] = v.vector[i];
    }
}

Virus::Virus(Virus &&v) noexcept {
    this->pm = v.pm;
    this->counter = v.counter;
    this->version = v.version;
    this->real_ver = v.real_ver;
    this->name = v.name;
    this->grade = v.grade;
    v.vector = nullptr;
}

Virus &Virus::operator=(Virus &&v) noexcept {
    if (this != &v) {
        this->pm = v.pm;
        this->counter = v.counter;
        this->version = v.version;
        this->real_ver = v.real_ver;
        this->name = v.name;
        this->grade = v.grade;

        delete[] this->vector;

        this->vector = v.vector;
        v.vector = nullptr;
    }
    return *this;
}

Virus &Virus::operator=(const Virus &v) {
    if (this != &v) {
        this->pm = v.pm;
        this->counter = v.counter;
        this->version = v.version;
        this->real_ver = v.real_ver;
        this->name = v.name;
        this->grade = v.grade;

        delete[] this->vector;

        this->vector = new int[World::dim];
        for (int i = 0; i < World::dim; i++)
            vector[i] = v.vector[i];
    }
    return *this;
}

bool Virus::operator<(const Virus &a) const {
    return (a.grade > this->grade);
}

bool Virus::operator<=(const Virus &a) const {
    return (a.grade == this->grade || this->grade < a.grade);

}

ostream &operator<<(ostream &out, const Virus &a) {
    if (a.real_ver == 0)
        out<<a.name<<" ";
    else
        out<<a.name<<"_"<< a.real_ver << " ";

    for (int i = 0; i < World::dim; i++)
        cout << a.vector[i]<<" ";

    cout<<endl;
    return out;
}

Virus& Virus::operator*() {
    for (int i = 0; i < this->pm ; i++) {
        int index_1 = rand() % World::dim;
        int index_2 = rand() % World::dim;
        swap(vector[index_1], vector[index_2]);
    }
    return *this;
}

void Virus::print_vector() {
    for (int i = 0; i < World::dim; i++)
        cout << vector[i]<<" ";
}

const string &Virus::getName() const {
    return name;
}

double Virus::getGrade() const {
    return grade;
}

int *Virus::getVersion() const {
    return version;
}

int Virus::getRealVer() const {
    return real_ver;
}

void Virus::setGrade() {

    double count = 0;

    for (int i = 0; i < World::dim; i++) {
        if (this->vector[i] == World::goal[i])
            count++;
    }
    double l = (1 - (count/World::dim));
    this->grade = l;
}

void Virus::setPm(int p) {
    Virus::pm = p;
}

void Virus::setVersion() {
    (*this->version)++;
}

void Virus::setRealVer(int realVer) {
    real_ver = realVer;
}

Virus::~Virus() {
    delete[] vector;
}







