//
// Practice 7. 행렬기본
// 2차원 배열 (2D Array practice)
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 100
#define COL 100

int main(){
    int array[ROW][COL];
    int row, col;
    scanf("%d %d", &row, &col);

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++)    array[i][j] = rand() % 1000;
    }

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++)    printf("[%3d] ", array[i][j]);
        printf("\n");
    }

    return 0;
}