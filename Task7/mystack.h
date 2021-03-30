#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define T char

typedef struct Node {
    T dat;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    int size;
} Stack;

void init(Stack *stack);
bool PushStack(Stack *stack, T value); 
T PopStack(Stack *stack);    
void printOneLinkCharNode(Node *n);
void printOneLinkCharStack(Stack *stack);
bool isEmpty(Stack *stack);
