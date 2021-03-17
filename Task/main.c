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

int Pow(int base, int exponent){
    int result = 1;
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
void Routes(int map[][5], int column, int row) {
    for (int i = 1; i < column; ++i) {
        map[i][0] = 1;
        for (int j = 1; j < row; ++j) {
            if (map[i][j] != 0) {
                map[i][j] = map[i - 1][j] + map[i][j - 1];
            }
            else continue;
        }
    }
}
void PrintArray(int map[], const int column, const int row) {
    for (int x = 0; x < column; ++x) {
        for (int y = 0; y < row; ++y) {
            printf("%5d", map[x * column + y]);
        }
        printf("\n");
    }
}

int main() {
/* Task1  Реализовать функцию перевода чисел из десятичной системы
 * в двоичную, используя рекурсию.  */
    int user_number = 0;
    printf("Please, enter the number: \n");
    scanf("%d", &user_number);
    DecToBin(user_number);
    printf("\n");

/*Task2 Реализовать функцию возведения числа [a] в степень [b]: */
    int a = 0, b = 0;
    printf("Please enter number and exponent: \n");
    scanf("%d%d", &a, &b);
    int result = Pow(a, b);
    printf("%d%s%d%s%d", a, " ^ ", b, " = ", result);
    printf("\n");
/* Recursively*/
    printf("Recursively: \n");
    printf("%d%s%d%s%d", a, " ^ ", b, " = ", RecPow(a, b));
    printf("\n");

/* Task3 Рекурсивно, используя свойство чётности степени
 * (то есть, если степень, в которую нужно возвести число, чётная,
 * основание возводится в квадрат, а показатель делится на два, а если
 * степень нечётная - результат умножается на основание, а показатель
 * уменьшается на единицу) */
    int prop_a = 0, prop_b = 0;
    printf("Please, enter numbers for PropertyPow function. \n");
    scanf("%d%d", &prop_a, &prop_b);
    int prop_result = PropertyPow(prop_a, prop_b);
    printf("Using parity property: \n");
    printf("%d%s%d%s%d\n", prop_a, " ^ ", prop_b, " = ", prop_result);

/* Task4 Реализовать нахождение количества маршрутов шахматного короля
 * с препятствиями (где единица - это наличие препятствия,
 * а ноль - свободная для хода клетка) */
    const int sizeX = 5;
    const int sizeY = 5;
    int map[][5] = {
            {1, 1, 1, 0, 0},
            {1, 1, 1, 1, 1},
            {1, 1, 0, 1, 1},
            {1, 0, 1, 1, 1},
            {1, 0, 1, 0, 1}
    };
    Routes(map, sizeX, sizeY);
    PrintArray(&map[0][0], sizeX, sizeY);

    return 0;
}
