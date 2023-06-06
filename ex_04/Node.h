//
// Created by ELON HADAD on 05/01/2023.
//

#ifndef EX_04_NODE_H
#define EX_04_NODE_H

template <typename T>

class Node {

public:
    explicit Node(T d);
    T getData() const;

    //  Getters
    Node<T> *getNext() const;
    Node<T> *getPrev() const;

    //  Setters
    void setNext(Node<T> *n);
    void setPrev(Node<T> *p);

private:
    T data;
    Node<T> *next;
    Node<T> *prev;
};

template<typename T>
Node<T>::Node(T d) {
    data = d;
    next = nullptr;
    prev = nullptr;
}

template<typename T>
T Node<T>::getData() const {
    return data;
}

template<typename T>
Node<T> *Node<T>::getNext() const {
    return next;
}

template<typename T>
Node<T> *Node<T>::getPrev() const {
    return prev;
}

template<typename T>
void Node<T>::setNext(Node<T> *n) {
    Node::next = n;
}

template<typename T>
void Node<T>::setPrev(Node<T> *p) {
    Node::prev = p;
}

#endif //EX_04_NODE_H
