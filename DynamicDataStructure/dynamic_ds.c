#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define T char
#define Size  1000


int cursor = -1;
T Stack[Size];

bool push(T data) {
    if (cursor < Size) {
        Stack[++cursor] = data;
        return true;
    }
    else {
        printf("Stacl overflow\n");
        return false;
    }
}

T pop() {
    if (cursor != -1) {
        return Stack[cursor--];
    }
    else {
        printf("Stack is empty\n");
        return -1;
    }
}

int main() {
   push('a');
   push('b');
   push('c');
   while (cursor != -1) {
       printf("%c\n", pop());
   }


    return 0;
}