#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Size 10

typedef struct {
    int priority;
    int data;
} Node;

Node* array[Size];

typedef struct {
    int head;
    int tail;
    int items;
} Auxiliary;


void InitStruct(Auxiliary *a) {
    for (int i = 0; i < Size; ++i) {
        array[i] = NULL;
    } 
    a->head = 0;
    a->tail = 0; 
    a->items = 0;
}


void InsertTo(Auxiliary *a, const int pr, const int data) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->priority = pr;
    int flag = 0;
    if (a->items == 0) {
        array[a->tail++] = node;
        a->items++;
    }
    else if(a->items == Size) {
        printf("Queue is full\n");
        return;
    }
    else {
        int i = 0;
        int index = 0;
        Node *temp;
        for (i = a->head; i < a->tail; ++i) {
            index = i % Size;
            if (array[index] == NULL) {
                break;
            }
            else {
                index++;
            }
        }
        flag = index % Size;
        ++i;
        while (i <= a->tail) {
            index = i % Size;            
            temp = array[index];
            array[index] = array[flag];
            array[flag] = temp;
            flag = index;
            ++i;
        } 
        array[flag] = node;
        a->items++;
        a->tail++;
    }
    
}

int GetIndex(Node *item) {
    for (int i = 0; i < Size; ++i) {
        if (array[i] == item) {
            return i;
        }
    }
    return -1;
}

Node* Remove(Auxiliary *a) {
    int index = 0;
    Node *maxPrior = array[0]; 
    if (a->items == 0) {
        return NULL;
    }
    for (int i = 1; i <= a->tail; ++i) {
        if (array[i] == NULL) break;
        if (maxPrior->priority > array[i]->priority) {
            maxPrior = array[i];
        }
    }
    index = GetIndex(maxPrior);
    if (index == -1) printf ("Something went wrong.../n");
    Node *temp = array[index]; 
    array[index] = NULL;
    a->items--;
    a->tail--;

    return temp;
    
}

void PrintQueue(Auxiliary *a) {
    printf("[ ");
    for (int i = 0; i < Size; ++i) {
        if (array[i] == NULL) {
            printf("[*, *] "); 
        }
        else {
            printf("[%d, %d] ", array[i]->priority, array[i]->data);
        }
    }
    printf("\n");
}

int main() {
/*Task1 Описать очередь с приоритетным исключением*/
//Testing
{    
    Auxiliary a;
    InitStruct(&a);
    InsertTo(&a, 3, 1);
    InsertTo(&a, 2, 1);
    InsertTo(&a, 1, 1);
    InsertTo(&a, 2, 5);
    InsertTo(&a, 1, 1);
    PrintQueue(&a);    
    Remove(&a);
    PrintQueue(&a);
    InsertTo(&a, 2, 4);
    PrintQueue(&a);
    Remove(&a);
    PrintQueue(&a);
    InsertTo(&a, 5, 5);
    PrintQueue(&a);
}



    
    return 0;
}