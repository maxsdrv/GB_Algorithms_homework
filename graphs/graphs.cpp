#include <iostream>

#include "mystack.h"

using namespace std;



int main() {
    auto *stack = new Stack;
    stack->pushStack(stack, 10);
    stack->pushStack(stack, 20);
    stack->Displayed(stack);

    delete stack;

    return 0;
}