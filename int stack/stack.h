#ifndef FREEPMAN_STACK_H
#define FREEPMAN_STACK_H
#include <cstddef>
#include <iostream>

class Stack{
    struct Node{ //
        int value;
        Node *prev;
    };
    Node *head = NULL;
public:
    Stack(); // To create an empty Stack
    Stack(int); // To create a Stack with first current value
    ~Stack(); // Procedure to make Stack empty, after delete it;
    Stack &push(int); // To add a new element on top of the Stack
    int pop(); // To remove an element on top of the Stack
    int top(); // To get an value of top's element
    int bot(); // To get an value of bottom's element
    void free(); // Is to free the elements
};

#endif