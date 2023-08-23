#include <iostream>
#include "stack.h"

int main(int argc, char* argv[]){
    Stack *newStack;
    newStack->push(2);
    std::cout<<newStack->pop()<<newStack->pop();
    return 0;
}