#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mystack.h"


int checkLeftBrackets(char brackets) {
    return (brackets == '(' || brackets == '[' || brackets == '<');
}

int checkRightBrackets(char brackets) {
    return (brackets == ')' || brackets == ']' || brackets == '>');
}

bool CorrectBrackets(char* brackets) {
    Stack *st = (Stack*) malloc(sizeof(Stack));
    init(st);
    char temp;
    PushStack(st, brackets[0]);
    for (int i = 1; i < strlen(brackets) + 1; ++i) {
        if (checkLeftBrackets(brackets[i])) {
            PushStack(st, brackets[i]);
        }
        else if (checkRightBrackets(brackets[i])) {
            PopStack(st);
        }
        else return false;
    }
    if (isEmpty(st)) {
        return true;
    }
    else return false;
}

int main() {
//    printOneLinkCharStack(st);
    char array[] = "(2/{5*(4+7)]";
    printf("Result = %d\n", CorrectBrackets(array));

    return 0;
}