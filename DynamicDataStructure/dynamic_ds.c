#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Size 1000


typedef struct PriorityQueue {
    int items;
    int top;
    int tail;
    int queue[Size];
} priority_queue;


bool Enqueue(priority_queue *pr, int data) {
    if (pr->items == Size) {
        printf("Queue is full\n");
        return false;
    }
    if (pr->tail == Size - 1) {
        pr->tail = -1;
    } 
    pr->queue[++pr->tail] = data;
    pr->items++;
    return true;
}

int dequeue(priority_queue *pr) {
    if (pr->items == 0) {
        printf("Queue is empty\n");
        return -1;
    }
    else {
        int tmp = pr->queue[pr->top++];
        pr->top %= Size;
        pr->items--;
        return tmp;
    }
}

void InitStruct(priority_queue *pr) {
    pr->items = 0;
    pr->tail = -1;
    pr->top = 0;
}


int main() {
    priority_queue pr;
    InitStruct(&pr);
    Enqueue(&pr, 1);
    Enqueue(&pr, 2);
    Enqueue(&pr, 3);
    Enqueue(&pr, 4);
    Enqueue(&pr, 5);
    while (pr.items > 0) {
        printf("%d ", dequeue(&pr));
    }

    return 0;
}