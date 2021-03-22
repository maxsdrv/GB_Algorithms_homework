#include <stdio.h>

#include "myarray.h"

void qs(int* array, const int first, const int last) {
    int i = first;
    int j = last;
    
    int x = array[(first + last) / 2];

    do {
        while (array[i] < x) {
            ++i;
        } 
        while (array[j] > x) {
            --j;
        }

        if (i <= j) {
            myswap(&array[i], &array[j]);
            ++i;
            --j;
        }

    } while (i <= j);

    if (i < last) qs(array, i, last);
    if (first < j) qs(array, first, j);
}

void sortInserts(int* arr, int len) {
    int temp = 0, pos = 0;
    for (int i = 1; i < len; ++i) {
        temp = arr[i];
        pos = i - 1;
        while (pos >= 0 && arr[pos] > temp) {
            arr[pos + 1] = arr[pos];
            pos--;
        }
        arr[pos + 1] = temp;
    }
}

void _quicksort(int *arr, int first, int last) {
    int i = first; 
    int j = last;
    const int redirect = 10;
    const int size_arr = ++last;
    printf("size arr = %d\n", size_arr);
}

void hard_sorts() {
    const int length = 20;
    int* array = init(array, length);
    fill(array, length);
    print(array, length, 3);
    // qs(array, 0, length - 1);
    // sortInserts(array, length);
    _quicksort(array, 0, length - 1);
    print(array, length, 3);
    
}

int main() {

    hard_sorts();

    return 0;
}