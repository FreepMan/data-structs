#ifndef FREEPMAN_STACK_CPP
#define FREEPMAN_STACK_CPP

#include "stack.h"

Stack &Stack::push(int val){
    Node *newEl = new(Node);
    newEl->value = val;
    newEl->prev = head;
    head = newEl;
    return *this;
}

int Stack::pop(){
    if(head == NULL){
        // Learn throw, catch, try to cont
        return -1;
    }
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
    return head->value;
}
int Stack::bot(){
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