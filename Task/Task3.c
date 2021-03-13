#include <stdio.h>

void rec(int a){
    printf("%5d", a);
    if (a > 0){
        rec(a - 1);
    }
}

int SumRec(int num){
    if (num > 0){
        return num % 10 + SumRec(num / 10);              
    }
    else return 0;
}

int triangle(int n){
    int result = 0;
    if (n == 1)
        result += 1;
    else
        result += n + triangle(n - 1);

    return result;
}

void PrintPyramid(int n){
    int i = 1;
    while (i <= n){
        int amnt = i;
        char shift[5];
        sprintf(shift, "%%%dd", n + 1 - i);
        printf(shift, i);
        while (--amnt != 0){
            printf("%2d", i);
        }
        printf("\n");
        i++;
    }
}

int main(){

    rec(10);
    printf("%s%d%s", "Result = ", SumRec(123), "\n");

    int result = triangle(5);
    PrintPyramid(result);

    return 0;
}