#include "geek.h"

void InitOneLinkList(OneLinkList *stack) {
    stack->head = NULL;
    stack->size = 0;
}

bool PushOneLinkStack(OneLinkList *stack, T value) {
    OneLinkNode *temp = (OneLinkNode*) malloc(sizeof(OneLinkNode));
    if (temp == NULL) {
        printf("Stack overflow\n");
        return false;
    }
    temp->dat = value;
    temp->next = stack->head;

    stack->head = temp;
    stack->size++;
    return true;
}

T PopOneLinkStack(OneLinkList *stack) {
    if (StackIsEmpty(stack)) {
        printf("Stack is empty \n");
        return -1;
    }
    OneLinkNode *temp = stack->head;
    T data = stack->head->dat;
    stack->head = stack->head->next;
    free(temp);
    stack->size--;
    return data;
}

void PrintOneLinkNode(OneLinkNode *n) {
    if (n == NULL) {
        printf("[]");
        return;
    }
    printf("[%d]", n->dat);
}

void PrintOneIntList(OneLinkList *stack) {
    OneLinkNode *current = stack->head;
    if (current == NULL) {
        PrintOneLinkNode(current);
    }
    else {
        do {
            PrintOneLinkNode(current);
            current = current->next;
        } while (current != NULL);
    }
    printf(" Size: %d \n", stack->size);
}

bool StackIsEmpty(OneLinkList *stack) {
    if (stack->size == 0) {
        return true;
    }
    return false;
}

void FreeOneLinkList(OneLinkList *stack) {
    while (stack->size != 0) {
        PopOneLinkStack(stack);
    }
    free(stack);
}
