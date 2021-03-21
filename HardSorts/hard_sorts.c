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


void hard_sorts() {
    const int length = 10;
    int* array = init(array, length);
    fill(array, length);
    print(array, length, 3);
    qs(array, 0, length - 1);
    print(array, length, 3);
    
}

int main() {

    hard_sorts();

    return 0;
}