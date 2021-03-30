#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mystack.h"


int checkLeftBrackets(char brackets) {
    return (brackets == '(' || brackets == '[' || brackets == '<'
            || brackets == '{');
}

int checkRightBrackets(char brackets) {
    return (brackets == ')' || brackets == ']' || brackets == '>'
            || brackets == '}');
}

    
bool CorrectBrackets(char* brackets) {
    Stack *st = (Stack*) malloc(sizeof(Stack));
    init(st);
    T temp;
    for (int i = 0; i < strlen(brackets) + 1; ++i) {
        if (checkLeftBrackets(brackets[i])) {
            PushStack(st, brackets[i]);
        }
        else if (checkRightBrackets(brackets[i])) {
            PopStack(st);
        }
    }
    if (isEmpty(st)) {
        return true;
    }
    else return false;
}

int main() {
    char array[] = "(2+(2*2))";
    printf("Result = %d\n", CorrectBrackets(array));
    char array2[] = "{2/{5*(4+7)]";
    printf("Result = %d\n", CorrectBrackets(array2));
    char array3[] = "2*5+4";
    printf("Result = %d\n", CorrectBrackets(array3));

    return 0;
}