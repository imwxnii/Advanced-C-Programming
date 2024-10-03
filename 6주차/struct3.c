#include <stdio.h>
#include <math.h>

// typedef int INT32;
// typedef char BYTE;
// typedef short int SHIRT;
// typedef double INT64;

// int main(){
//     int i = 10;
//     INT32 j = 10;
//     BYTE b = 20;
//     SHORT s = 32;
//     INT64 = 123000000000000;

//     printf("%d, %d\n", i, j);

//     return 0;
// }

typedef struct point{
    int x;
    int y;
} POINT;

typedef struct{
    POINT center;
    double radius;
} CIRCLE;

typedef struct rect{
    POINT lb;
    POINT rt;
} RECT;

double dist(POINT p1, struct point p2){
    return sqrt(pow((p2.x - p1.x),2) + pow((p2.y - p1.y),2));
}