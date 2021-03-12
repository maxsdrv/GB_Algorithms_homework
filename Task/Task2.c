#include <stdio.h>
#include <math.h>


int CheckDecimal(const int n){
    if (n < 2) return 0;
    for (int i = 2; i < sqrt(n); ++i){
        if (n % i == 0){
            return 0;
        }
    }
    return 1;
}

int main() {

    int n = 0;
    scanf("%d", &n);
    if (CheckDecimal(n)){
        printf("True\n");
    }
    else printf("False\n");

    return 0;
}