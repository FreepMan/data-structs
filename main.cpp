#include <iostream>
#include "template-stack/stack.h"

int main(){
    Stack<int> stack;
    stack.push(2);
    std::cout<<stack.top()<<std::endl;
    std::cout<<stack.bot()<<std::endl;
    std::cout<<stack.pop()<<std::endl;
    std::cout<<stack.top()<<std::endl;
    return 0;
}