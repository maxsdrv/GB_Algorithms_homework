#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//Инициализируем 2-мерный массив
int** init2dIntArray(int** arr, const int row, const int col) {
    arr = (int**) calloc(sizeof(int*), row);
    for (int i = 0; i < row; ++i) {
        *(arr + i) = (int*) calloc(sizeof(int), col);
    }
    return arr;
}

//Заполняем 2-мерный массив
void fill2dIntArray(int** arr, const int row, const int col, const int value) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            *((*(arr + i)) + j) = rand() % value;
        }
    }
}

//Печать массива
void print2dIntArray(int** arr, const int row, const int col, int offset) {
    char format[7];
    sprintf(format, "%%%dd", offset);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            printf(format, *((*(arr + i)) + j));
        }
        printf("\n");
    }
}

//Функция swap
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort2dIntArray(int** arr, const int row, const int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            int m = i; // текущий столбец
            int n = j + 1; //следующий элемент
            while (true) {
                if (n == col) { //здесь идёт проверка на границы массива
                    n = 0;
                    m++;
                    if (m == row) break;// по достижению конца массива выходим из цикла while
                }
                if (arr[i][j] > arr[m][n]) {
                    swap(&arr[i][j], &arr[m][n]);
                }
                n++;
            }
        }
    }
}

//Функция для очистки выделенной памяти
void freeAllocation(int** arr, const int row) {
    for (int i = 0; i < row; ++i) {
        free(arr[i]);
    }
    free(arr);
}

//Основная функция вызовов 
void lesson_arrays() {
    const int row = 4;
    const int col = 5;
    const int length = 10;
    int** array = (int **) init2dIntArray(array, row, col);
    fill2dIntArray(array, row, col, 100);
    print2dIntArray(array, row, col, 3);
    printf("\n");
    sort2dIntArray(array, row, col);
    print2dIntArray(array, row, col, 3);
    freeAllocation(array, row);

}

void TPC_algorithm() {
    const int size_array = 10;
    double* arrayInt = (int*) calloc(sizeof(int), size_array);
    int y = 0;


    free(arrayInt);
}

int main() {
 /*Реализовать пузырьковую сортировку двумерного массива*/
   lesson_arrays();

/*Реализовать алгоритм Трабба-Прадо-Кнута в коде на языке С*/
   TPC_algorithm();


    return 0;
}
