#include <stdio.h>

#include "myarray.h"

//Quick Sort 
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

//Sort Insert
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

int partition(int* arr, int first, int last) {
    int i = first;
    int j = last;

    int x = arr[(first + last) / 2]; 
    
}

//The function will return the median of 3 elements
int median(int f, int m, int l) {
    if ((m < f && f < l) || (m > f && f > l)) return f;
    if ((f < m && m < l) || (f > m && m > l)) return m;
    return l; 
}

//Improved Quick Sort algorithm
void _quicksort(int *arr, int first, int last) {
    const int M = 10;
    int med = median(arr[first], arr[(first + last) / 2], arr[last]);
    if (last - first <= M) {
        sortInserts(arr, ++last);
    }
    myswap(&arr[med], &arr[(first + last) / 2]);
    int i = partition(arr, first, last);
    _quicksort(arr, first, last);
    _quicksort(arr, i + first, last);
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