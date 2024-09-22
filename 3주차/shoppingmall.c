// 변경사항
// 메뉴 생성(입고, 판매, 상품현황, 프로그램 종료)
// 메뉴 반복적으로 동작하게 변경
// 5개의 상품으로 고정
// 초기 메뉴는 main 함수에, 추가 메뉴들은 함수로 변경

#include <stdio.h>
#define MAX_CNT 5

void showStatus(int products, int* stock, int minus_all, int plus_all, int* max_id, int* max_sales, int* min_id, int* min_sales, int* minus);
void storeAll(int products, int* plus, int* plus_all, int* stock);
void storeOne(int products, int* plus, int* plus_all, int* stock);
void sellAll(int products, int* minus, int* minus_all, int* stock);
void sellOne(int products, int* minus, int* minus_all, int* stock);
void salesQuantity(int products, int* plus, int* minus, int* stock, int* plus_all, int* minus_all, int* min_sales, int* min_id, int* max_id, int* max_sales);
void stockQuantiiy(int products, int* stock);
void outOfStock(int products, int* stock);

int main() {
    int products = MAX_CNT;
    int plus[MAX_CNT] = {0}; 
    int minus[MAX_CNT] = {0};
    int stock[MAX_CNT] = {0};
    int plus_all = 0;
    int minus_all = 0;
    int max_id = 0;
    int max_sales = 0;
    int min_id = 0;
    int min_sales = 0;
    int menu;
    int choice;

    printf("[쇼핑몰 관리 프로그램]\n");

    while (1) {
        printf("> 원하는 메뉴를 선택하세요.(1. 입고, 2. 판매, 3. 상품현황, 4. 종료)\n");
        printf("> ");
        scanf("%d", &menu);

    switch (menu) {
            case 1:
                printf("입고수량 입력 : 전체 상품 입고수량 입력 1, 개별 상품 입력 2를 선택\n");
                scanf("%d", &choice);
                if (choice == 1) {
                    storeAll(products, plus, &plus_all, stock);
                    break;
                }
                else if (choice == 2) {
                    storeOne(products, plus, &plus_all, stock);
                    break;
                }
                else {
                    printf("잘못 입력하셨습니다. 초기 메뉴로 돌아갑니다.\n");
                    break;
                }
                
                break;
            case 2:
                printf("판매수량 입력 : 전체 상품 판매수량 입력 1, 개별 상품 입력 2를 선택\n");
                scanf("%d", &choice);
                if (choice == 1) {
                    sellAll(products, minus, &minus_all, stock);
                    break;
                }
                else if (choice == 2) {
                    sellOne(products, minus, &minus_all, stock);
                    break;
                }
                else {
                    printf("잘못 입력하셨습니다. 초기 메뉴로 돌아갑니다.\n");
                    break;
                }
            case 3:
                showStatus(products, stock, minus_all, plus_all, &max_id, &max_sales, &min_id, &min_sales, minus);
                break;
            case 4:
                printf("프로그램을 종료합니다.\n");
                return 0;
            default:
                printf("잘못된 입력입니다. 다시 시도해주세요.\n");
        }
    }
}

void showStatus(int products, int* stock, int minus_all, int plus_all, int* max_id, int* max_sales, int* min_id, int* min_sales, int* minus) {
    for(int i = 0; i < products; i++){
        if (i == 0) {
            *min_sales = minus[i];
            *min_id = i;
            *max_sales = minus[i];
            *max_id = i;
        }

        if (minus[i] > *max_sales) {
            *max_sales = minus[i];
            *max_id = i;
        }

        if (minus[i] < *min_sales) {
            *min_sales = minus[i];
            *min_id = i;
        }
    }
    printf("재고 수량 : ");
    for(int i = 0; i < products; i++) {
        printf("%d ", stock[i]);
    }
    printf("\n");
    printf("총 판매량 : %d (판매율 %.2f%%)\n", minus_all, ((float)minus_all/plus_all)*100);
    printf("가장 많이 판매된 상품 : ID %d, 판매량 %d\n", *max_id+1, *max_sales);
    printf("가장 적게 판매된 상품 : ID %d, 판매량 %d\n", *min_id+1, *min_sales);
    for(int i = 0; i < products; i++) {
        if(stock[i] <= 2) {
            printf("상품 ID %d : 재고부족(%d)\n", i+1, stock[i]);
        }
    }
}

void storeAll(int products, int* plus, int* plus_all, int* stock) {
    for(int i = 0; i < products; i++) {
        scanf("%d", &plus[i]);
        stock[i] += plus[i];
        *plus_all += plus[i];
    }
}

void storeOne(int products, int* plus, int* plus_all, int* stock) {
    int id;
    printf("상품ID : ");
    scanf("%d", &id);
    printf("입고수량 : ");
    scanf("%d", &plus[id]);
    stock[id] += plus[id];
    *plus_all += plus[id];
}

void sellAll(int products, int* minus, int* minus_all, int* stock) {
    for(int i = 0; i < products; i++) {
        scanf("%d", &minus[i]);
        stock[i] -= minus[i];
        *minus_all += minus[i];
    }
}

void sellOne(int products, int* minus, int* minus_all, int* stock) {
    int id;
    printf("상품ID : ");
    scanf("%d", &id);
    printf("판매수량 : ");
    scanf("%d", &minus[id]);
    stock[id] -= minus[id];
    *minus_all += minus[id];
}

void salesQuantity(int products, int* plus, int* minus, int* stock, int* plus_all, int* minus_all, int* min_sales, int* min_id, int* max_id, int* max_sales) {
    for(int i = 0; i < products; i++) {
        scanf("%d", &minus[i]);
        stock[i] = plus[i] - minus[i];
        *minus_all += minus[i];

        if (i == 1) {
            *min_sales = minus[i];
            *min_id = i;
            *max_sales = minus[i];
            *max_id = i;
        }

        if (minus[i] > *max_sales) {
            *max_sales = minus[i];
            *max_id = i;
        }

        if (minus[i] < *min_sales) {
            *min_sales = minus[i];
            *min_id = i;
        }
    }
}

void stockQuantiiy(int products, int* stock) {
    printf("재고 수량 : ");
    for(int i = 0; i < products; i++) {
        printf("%d ", stock[i]);
    }
    printf("\n");
}

void outOfStock(int products, int* stock) {
    for(int i = 0; i < products; i++) {
        if(stock[i] <= 2) {
            printf("상품 ID %d : 재고부족(%d)\n", i, stock[i]);
        }
    }
}