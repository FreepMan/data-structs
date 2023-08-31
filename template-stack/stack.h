#ifndef FREEPMAN_TEMPLSTACK_H
#define FREEPMAN_TEMPLSTACK_H

template<typename T>
class Stack{
private:
    struct Node{
        T data;
        Node* prev;
    };
    Node head;
public:
    Stack() {};
    Stack(T);
    Stack &push(T);
    T pop();
    T top();
    T bot();
    void free();
};

#endif