#include <stdio.h>

int PropertyPow(int base, int exponent){
    if (exponent == 0) return 1;
    if (exponent % 2 != 0){
        return PropertyPow(base, exponent - 1) * base;
    }
    int result = PropertyPow(base, exponent / 2);
    return result * result;
}

int RecPow(int base, int exponent){
    if (exponent > 1){
        return RecPow(base, --exponent) * base;
    }
}

float Pow(float base, float exponent){
    float result = 1;
    while (exponent != 0){
        result *= base;
        --exponent;
    }
    return result;
}

void DecToBin(int n){
    if (n > 0){
        DecToBin(n / 2);
    }
    printf("%d", n % 2);
}

int main() {
/* Task1  Реализовать функцию перевода чисел из десятичной системы
 * в двоичную, используя рекурсию.  */
    /*int user_number = 0;
    printf("Please, enter the number: \n");
    scanf("%d", &user_number);
    DecToBin(user_number);*/

/*Task2 Реализовать функцию возведения числа [a] в степень [b]: */
    int a = 5, b = 3;
    int result = Pow(a, b);
    printf("%d", result);
    printf("\n");
/* Recursively*/
    printf("%d", RecPow(a, b));
    printf("\n");

/* Task3 Рекурсивно, используя свойство чётности степени
 * (то есть, если степень, в которую нужно возвести число, чётная,
 * основание возводится в квадрат, а показатель делится на два, а если
 * степень нечётная - результат умножается на основание, а показатель
 * уменьшается на единицу) */
    int prop_a = 10, prop_b = 2;
    int prop_result = PropertyPow(prop_a, prop_b);
    printf("%d\n", prop_result);

    return 0;
}
