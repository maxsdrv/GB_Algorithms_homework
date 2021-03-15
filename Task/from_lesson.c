#include <stdio.h>

#define HEIGHT 8
#define WIDTH 8
#define QUEENS 8

int board[HEIGHT][WIDTH];

void Annull(){
    for (int x = 0; x < HEIGHT; ++x){
        for (int y = 0; y < WIDTH; ++y){
            board[x][y] = 0;
        }
    }
}

void PrintBoard(){
    for (int x = 0; x < HEIGHT; ++x ){
        for (int y = 0; y < WIDTH; ++y){
            printf("%2d", board[x][y]);
        }
        printf("\n");
    }

}

int CheckQueen(int x, int y) {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            if (board[i][j] != 0) {
            }
        }
    }
}

int CheckBoard() {
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
           if (board[y][x] != 0) {
               if (CheckQueen(y, x) == 0){
                   return 0;
               }
           }
        }
    }
    return 1;
}

int Queens(int n){
    if (CheckBoard() == 0) return 0;
    if (n == QUEENS + 1) return 1;
    for (int y = 0; y < HEIGHT; ++y){
        for (int x = 0; x < WIDTH; ++x){
            if (board[y][x] == 0) {
                board[y][x] = n;
                if (Queens(n + 1))
                    return 1;
                board[y][x] = 0;
            }
        }
    }
    return 0;
}

int main(){


    return 0;
}
