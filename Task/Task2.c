#include <stdio.h>
#include <math.h>


int CheckPrime(const int n){
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
    if (CheckPrime(n)){
        printf("True\n");
    }
    else printf("False\n");

    return 0;
}
