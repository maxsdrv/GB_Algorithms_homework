#include <stdio.h>
#include <stdlib.h>

#include "mystack.h"

int main() {
    Stack *st = (Stack*) malloc(sizeof(Stack));
    init(st);
    PushStack(st, 'a');
    PushStack(st, 'b');
    PushStack(st, 'c');
    PushStack(st, 'd');
    PushStack(st, 'f');
    printOneLinkCharStack(st);


    return 0;
}