#include <stdio.h>
#define MAX_CNT 5

typedef struct product{
    int id;
    char name[100];
    int price;
    int stock;
    int store;
    int sell;
    int sell_price;
} PRODUCT;

void showStatusOne(int cnt, PRODUCT* product);
void showStatus(int cnt, int minus_all, int plus_all, int* max_id, int* max_sales, int* min_id, int* min_sales, PRODUCT* product);
void storeOne(int cnt, int* plus_all, PRODUCT* product);
void sellOne(int cnt, int* minus_all, PRODUCT* product);

int main() {
    PRODUCT product[MAX_CNT] = {0};
    int cnt = MAX_CNT;
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
        printf("> 원하는 메뉴를 선택하세요.(1. 입고, 2. 판매, 3. 개별현황, 4. 전체현황, 5. 종료)\n");
        printf("> ");
        scanf("%d", &menu);

    switch (menu) {
            case 1:
                storeOne(cnt, &plus_all, product);
                break;
            case 2:
                sellOne(cnt, &minus_all, product);
                break;
            case 3:
                showStatusOne(cnt, product);
                break;
            case 4:
                showStatus(cnt, minus_all, plus_all, &max_id, &max_sales, &min_id, &min_sales, product);
                break;
            case 5:
                printf("프로그램을 종료합니다.\n");
                return 0;
            default:
                printf("잘못된 입력입니다. 다시 시도해주세요.\n");
        }
    }
}

void showStatusOne(int cnt, PRODUCT* product){
    int id;
    printf("상품ID : ");
    scanf("%d", &id);
    printf("상품명 : %s\n", product[id].name);
    printf("상품가격 : %d\n", product[id].price);
    printf("재고 : %d\n", product[id].stock);
    printf("입고량 : %d\n", product[id].store);
    printf("판매량 : %d\n", product[id].sell);
    printf("총판매금액 : %d\n", product[id].sell_price);
}

void showStatus(int cnt,int minus_all, int plus_all, int* max_id, int* max_sales, int* min_id, int* min_sales, PRODUCT* product) {
    for(int i = 0; i < cnt; i++){
        if (i == 0) {
            *min_sales = product[i].sell;
            *min_id = i;
            *max_sales = product[i].sell;
            *max_id = i;
        }

        if (product[i].sell > *max_sales) {
            *max_sales = product[i].sell;
            *max_id = i;
        }

        if (product[i].sell < *min_sales) {
            *min_sales = product[i].sell;
            *min_id = i;
        }
    }
    printf("재고 수량 : ");
    for(int i = 0; i < cnt; i++) {
        printf("%d ", product[i].stock);
    }
    printf("\n");
    printf("총 판매량 : %d (판매율 %.2f%%)\n", minus_all, ((float)minus_all/plus_all)*100);
    printf("가장 많이 판매된 상품 : ID %d (%s), 판매량 %d\n", *max_id + 1, product[*max_id].name, *max_sales);
    printf("가장 적게 판매된 상품 : ID %d (%s), 판매량 %d\n", *min_id + 1, product[*min_id].name, *min_sales);
    for(int i = 0; i < cnt; i++) {
        if(product[i].stock <= 2) {
            printf("상품 ID %d : 상품명 : %s 재고부족(%d)\n", i + 1, product[i].name, product[i].stock);
        }
    }
}

void storeOne(int cnt, int* plus_all, PRODUCT* product) {
    int id;
    int store;
    int price;
    printf("상품ID : ");
    scanf("%d", &id);
    printf("상품명 : ");
    scanf("%s", product[id].name);
    printf("입고수량 : ");
    scanf("%d", &store);
    printf("판매가격 : ");
    scanf("%d", &price);
    product[id].price = price;
    product[id].stock += store;
    product[id].store += store;
    *plus_all += store;
}

void sellOne(int cnt, int* minus_all, PRODUCT* product) {
    int id;
    int sell;
    printf("상품ID : ");
    scanf("%d", &id);
    printf("판매수량 : ");
    scanf("%d", &sell);
    product[id].stock -= sell;
    product[id].sell += sell;
    product[id].sell_price += (product[id].price * sell);
    *minus_all += sell;
}