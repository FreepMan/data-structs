#include <iostream>
#include "template-stack/stack.h"

int main(){
    Stack<int> a(2);
    std::cout<<a.top()<<a.pop();
    return 0;
}

