#include "mystack.h"


void init(Stack *stack) {
    stack->head = NULL;
    stack->size = 0;
}

bool PushStack(Stack *stack, T value) {
    Node *temp = (Node*) malloc(sizeof(Node));
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

T PopStack(Stack *stack) {
    if (stack->size == 0) {
        printf("Stack is empty \n");
        return -1;
    }
    Node *temp = stack->head;
    T data = stack->head->dat;
    stack->head = stack->head->next;
    free(temp);
    stack->size--;
    return data;

}

void printOneLinkCharNode(Node *n) {
    if (n == NULL) {
        printf("[]");
        return;
    }
    printf("[%c]", n->dat);
}

void printOneLinkCharStack(Stack *stack) {
    Node *current = stack->head;
    if (current == NULL) {
        printOneLinkCharNode(current);
    }
    else {
        do {
            printOneLinkCharNode(current);
            current = current->next;
        } while (current != NULL);
    }
    printf(" Size: %d \n", stack->size);
}


















