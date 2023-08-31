#ifndef FREEPMAN_TEMPLSTACK_CPP
#define FREEPMAN_TEMPLSTACK_CPP
#include "stack.h"

template<typename T>
Stack<T>::Stack(T val){
    push(val);
}

template<typename T>
Stack<T> &Stack<T>::push(T val){
    Node* newElement = new Node;
    newElement->data = val;
    newElement->prev = head;
    head = newElement;
    return *this;
}

template<typename T>
T Stack<T>::pop(){
    if(head == nullptr){
        throw std::out_of_range("Stack is empty");
    }
    Node *nextEl = head->prev;
    T toReturnData = head->data;
    delete(head);
    head = nextEl;
    return toReturnData;
}

template<typename T>
T Stack<T>::top(){
    return head->data;
}

template<typename T>
T Stack<T>::bot(){
    Node *currentEl = Head;
    while(currentEl != nullptr){
        currentEl = currentEl->prev;
    }
    return currentEl->data;
}

template<typename T>
void Stack<T>::free(){
    while(head != nullptr){
        pop();
    }
}

#endif