#ifndef FREEPMAN_STACK_CPP
#define FREEPMAN_STACK_CPP

#include <stdexcept>
#include "stack.h"

Stack &Stack::push(int val){
    Node *newEl = new(Node);
    newEl->value = val;
    newEl->prev = head;
    head = newEl;
    return *this;
}

int Stack::pop(){
    if(head == NULL)
        std::out_of_range("Can't pop empty stack!");
    int returnValue = head->value;
    Node *temp = head;
    head = head->prev;
    delete(temp);
    return returnValue;
}

Stack::Stack(){}

Stack::Stack(int val){
    push(val);
}

int Stack::top(){
    if(head == NULL)
        std::out_of_range("Stack is empty.");
    return head->value;
}
int Stack::bot(){
    if(head == NULL)
        std::out_of_range("Stack is empty.");
    Node *temp = head;
    while(temp->prev != NULL) temp = temp->prev;
    return temp->value;
}
void Stack::free(){
    while(head != NULL){
        pop();
    }
}

Stack::~Stack(){
    free();
}

#endif