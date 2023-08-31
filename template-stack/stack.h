#ifndef FREEPMAN_TEMPLSTACK_H
#define FREEPMAN_TEMPLSTACK_H

#include <stdexcept>

template<typename T>
class Stack{
private:
    struct Node{
        T data;
        Node* prev;
    };
    Node *head = nullptr;
public:
    Stack() {};
    Stack(T);
    Stack &push(T);
    T pop();
    T top();
    T bot();
    void free();
};

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
        throw std::out_of_range("Can not pop an empty stack!");
    }
    Node *nextEl = head->prev;
    T toReturnData = head->data;
    delete(head);
    head = nextEl;
    return toReturnData;
}

template<typename T>
T Stack<T>::top(){
    if(head == nullptr){
        throw std::out_of_range("There is no data!");
    }
    return head->data;
}

template<typename T>
T Stack<T>::bot(){
    if(head == nullptr){
        throw std::out_of_range("There is no data!");
    }
    Node *currentEl = head;
    while(currentEl->prev != nullptr){
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