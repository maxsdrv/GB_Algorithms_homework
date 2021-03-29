#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Size 10
#define sizeStack 1000
#define T int

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


Node* Remove(Auxiliary *a) {
    int index = 0;
    int maxPos = array[0]->priority;
    if (a->items == 0) {
        return NULL;
    }
    for (int i = 1; i < a->tail; ++i) {
        if (maxPos > array[i]->priority) {
            maxPos = array[i]->priority;
            index = i;
        }
    }
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

/* __________________________________________________________*/
int top = -1;
T Stack[Size];

bool PushStack(int data) {
    if (top < Size) {
        Stack[++top] = data;
        return true;
    }
    else {
        printf("Stack overflow\n");
        return false;
    }
}


T PopStack() {
    if (top != -1) {
        return Stack[top--];
    }
    else {
        printf("Stack is empty\n");
        return -1;
    }
}

void DecToBin(int number) {
    while (number > 0) {
        int remainder = number % 2;
        number /= 2;
        PushStack(remainder);
    }
    while (top != -1) {
        int item = 0;
        item = PopStack();
        printf("%d", item);
    }
    printf("\n");
}



int main() {
/*Task1 Описать очередь с приоритетным исключением*/
//Testing
{   
    printf("Start test Task1 ....\n");
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
    printf("End test Task1.\n");
    /*Не знаю  почему коряво освобождает память, по отладчику 
    в массиве мусор, а в консоль выводит значения почему-то*/
    for (int i = 0; i < a.tail; ++i) {
        printf("%d %d\n", array[i]->priority, array[i]->data);
        free(array[i]);
    }
    for (int i = 0; i < a.tail; ++i) {
        printf("%d %d\n", array[i]->priority, array[i]->data);
    }
}

/* Task2. Реализовать перевод из десятичной в двоичную
 систему счисления с использованием стека. */
    int number = 10;
    printf("Convert a Decimal number to Binary number\n");
    printf("Decimal Number = %d \n", number);
    printf("Binary number = ");
    DecToBin(number);
    printf("\n");
    
    return 0;
}