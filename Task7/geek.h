#ifndef TASK7_GEEK_H
#define TASK7_GEEK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define T   int

typedef struct OneLinkNode {
    T dat;
    struct OneLinkNode *next;
} OneLinkNode;

typedef struct {
    OneLinkNode *head;
    int size;
} OneLinkList;

void InitOneLinkList(OneLinkList *stack);
bool PushOneLinkStack(OneLinkList *stack, T value);
T PopOneLinkStack(OneLinkList *stack);
void PrintOneLinkNode(OneLinkNode *n);
void PrintOneIntList(OneLinkList *stack);
bool StackIsEmpty(OneLinkList *stack);
void FreeOneLinkList(OneLinkList *stack);

#endif //TASK7_GEEK_H
