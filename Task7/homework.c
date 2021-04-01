#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "geek.h"

int checkLeftBrackets(char brackets) {
    return (brackets == '(' || brackets == '[' || brackets == '<'
            || brackets == '{');
}

int checkRightBrackets(char brackets) {
    return (brackets == ')' || brackets == ']' || brackets == '>'
            || brackets == '}');
}


bool CorrectBrackets(char* brackets) {
    OneLinkList *st = (OneLinkList *) malloc(sizeof(OneLinkList));
    InitOneLinkList(st);
    for (int i = 0; i < strlen(brackets) + 1; ++i) {
        if (checkLeftBrackets(brackets[i])) {
            PushOneLinkStack(st, brackets[i]);
        }
        else if (checkRightBrackets(brackets[i])) {
            PopOneLinkStack(st);
        }
    }
    if (StackIsEmpty(st)) {
        return true;
    }
    else {
        free(st);
        return false;
    }
}

void CopyList(OneLinkList* from, OneLinkList *to) {
    int ElementsLeftCopy = from->size;
    OneLinkNode *current = from->head;
    while (ElementsLeftCopy != 0) {
        for (int i = 0; i < ElementsLeftCopy - 1; ++i) {
            current = current->next;
        }
        PushOneLinkStack(to, current->dat);
        ElementsLeftCopy--;
        current = from->head;
    }
}

int main() {
    /*Task 1.) Написать программу, которая определяет, является ли введенная скобочная
     * последовательность правильной. */
    printf("\n ------Exercise 1 -------\n");
    char array[] = "(2+(2*2))";
    printf("Result = %d\n", CorrectBrackets(array));
    char array2[] = "{2/{5*(4+7)]";
    printf("Result = %d\n", CorrectBrackets(array2));
    char array3[] = "2*5+4";
    printf("Result = %d\n", CorrectBrackets(array3));

    /*2.) Создать функцию, копирующую односвязный список (без удаления первого списка).
    Входные данные: OneLinkList* from - начало списка с которого производится копирование,
    OneLinkList* to - начало списка в которое производится копирование
    Выходные данные: void*/
    printf("\n -----Exercise 2------ \n");
    OneLinkList* originalList = (OneLinkList*) malloc(sizeof(OneLinkList));
    InitOneLinkList(originalList);
    for (int i = 9; i > 0; --i) {
        PushOneLinkStack(originalList, i);
    }
    OneLinkList* listCopy = (OneLinkList*) malloc(sizeof(OneLinkList));
    InitOneLinkList(listCopy);

    PrintOneIntList(originalList);
    CopyList(originalList, listCopy);
    PrintOneIntList(listCopy);

    FreeOneLinkList(originalList);
    FreeOneLinkList(listCopy);


    return 0;
}