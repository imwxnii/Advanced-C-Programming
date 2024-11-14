//
// 11주차3. DL 3. 동적할당_활용1
// 동적할당 실습 #2 - 구조체 배열 동적 생성하기
//

#include <stdio.h>
#include <stdlib.h>

typedef struct point{
    int x;
    int y;
} POINT;

int main(){
    POINT* points;
    int count;
    scanf("%d", &count);

    points = (POINT*)malloc(sizeof(POINT) * count);

    for(int i = 0; i < count; i++){
        points[i].x = rand() % 100;
        points[i].y = rand() % 100;
    }

    for(int i = 0; i < count; i++){
        printf("x - %d, y - %d\n", points[i].x, points[i].y);
    }

    free(points);
    
    return 0;
}