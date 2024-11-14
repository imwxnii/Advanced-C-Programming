//
// 11주차3. DL 3. 동적할당_활용1
// 동적할당 실습 #3 - 동적할당 활용하기
//

#include <stdio.h>
#include <stdlib.h>

typedef struct point{
    int x;
    int y;
} POINT;

int inputMenu(void){
    int input;
    printf("메뉴입력(1. 구조체 만들기, 2. 구조체 출력하기, -1. 종료) : ");
    scanf("%d", &input);
    return input;
}

int main(){
    int menu;

    do{
        menu = inputMenu();
        if(menu == 1){
            //구조체 만들기
        }else if(menu == 2){
            //구조체 출력하기
        }else if(menu == -1){
            printf("프로그램을 종료합니다.\n");
        }
    }while(menu > 0);

    return 0;
}