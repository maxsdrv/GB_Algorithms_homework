#include <stdio.h>
#include <stdlib.h>



int* init(int* arr, const int size) {
    arr = (int*) calloc(sizeof(int), size);

    return arr; 
}

int* fill(int* arr, const int size) {
    for (int i = 0; i < size; ++i) {
        *(arr + i) = rand() % 100;
    }

    return arr;
}

void print(int* arr, const int size, int offset) {
    char format[7];
    sprintf(format, "%%%dd", offset);
    for (int i = 0; i < size; ++i) {
        printf(format, *(arr + i));
    }
    printf("\n"); 
}

void myswap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
    