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



//The function will return the median of 3 elements
int median(const int f, const int m, const int l) {
    if ((m < f && f < l) || (m > f && f > l)) return f;
    if ((f < m && m < l) || (f > m && m > l)) return m;
    return l;
}

int getIndex(const int* arr, const int len, int index) {
    for (int i = 0; i < len; ++i) {
        if (arr[i] == index) {
            index = i;
        }
    }
    return index;
}

//Improved Quick Sort algorithm
void my_QuickSort(int *arr, int first, int last) {
    const int M = 10;
    int med = median(arr[first], arr[(first + last) / 2], arr[last]);
    if (last - first <= M) {
        sortInserts(arr, ++last);
    }
    myswap(&arr[getIndex(arr, last, med)], &arr[(first + last) / 2]);
    qs(arr, first, last);
}

void BucketSort(int* arr, int length) {
    const int max = length;
    const int b = 10;
    const int maxItem = 1000000000;
    int buckets[b][max + 1];
    for (int i = 0; i < b; ++i) {
        buckets[i][max] = 0;
    }
    for (int digit = 1; digit < maxItem; digit *= 10) {
        for (int i = 0; i < max; ++i) {
            if (arr[i] % 2 == 0) {
                int d = (arr[i] / digit) % b;

                int counter = buckets[d][max];
                buckets[d][counter] = arr[i];
                counter++;
                buckets[d][max] = counter;

                arr[i] = -1;
            }
        }
        int idx = 0;
        for (int i = 0; i < b; ++i) {
            for (int j = 0; j < buckets[i][max]; ++j) {
                while (arr[idx] != -1) {
                    idx++;
                }
                arr[idx] = buckets[i][j];
            }
            buckets[i][max] = 0;
        }
    }
    
}


void hard_sorts() {
    const int length = 20;
    int* array = init(array, length);
    fill(array, length);
    print(array, length, 3);
    /*Task1. Описать в коде улучшенный алгоритм быстрой сортировки - описана в видео "Быстрая Сортировка. Улучшения."*/
    my_QuickSort(array, 0, length - 1);
    print(array, length, 3);

    /*Task2.  Сортировать в массиве целых положительных чисел только чётные числа, нечётные оставив на своих местах
     при помощи алгоритма блочной сортировки */
    fill(array, length);
    print(array, length, 3);
    BucketSort(array, length);
    print(array, length, 3);

    free(array);

}

int main() {

    hard_sorts();

    return 0;
}
