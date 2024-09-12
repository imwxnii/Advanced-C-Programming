// # 변경 사항
// - 1번째 인덱스부터 시작하도록 변경
// - 총 판매량 추가
// - 가장 많이/적게 판매된 상품 출력
// - 2개 이하의 재고인 상품 출력
// - 기능 구현된 것들 함수로 변경

#include <stdio.h>
#define MAX_CNT 100

void quantityInStock(int products, int* plus, int* plus_all) { // 상품 별 입고수량 입력
    for(int i = 1; i <= products; i++) {
        scanf("%d", &plus[i]);
        *plus_all += plus[i];
    }
}

// 상품 별 출고수량 및 재고수량 입력, MAX/MIN 재고와 id 선택
void salesQuantity(int products, int* plus, int* minus, int* stock, int* plus_all, int* minus_all, int* min_sales, int* min_id, int* max_id, int* max_sales) {
    for(int i = 1; i <= products; i++) {
        scanf("%d", &minus[i]);
        stock[i] = plus[i] - minus[i]; // 재고 계산
        *minus_all += minus[i]; // 전체 출고량 누적

        if (i == 1) { // 첫 번째 상품 기준으로 min/max 설정
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

void stockQuantiiy(int products, int* stock) { // 재고 수량 출력
    printf("재고 수량 : ");
    for(int i = 1; i <= products; i++) {
        printf("%d ", stock[i]);
    }
    printf("\n");
}

void outOfStock(int products, int* stock) { // 재고 부족 출력
    for(int i = 1; i <= products; i++) {
        if(stock[i] <= 2) {
            printf("상품 ID %d : 재고부족(%d)\n", i, stock[i]);
        }
    }
}

int main() {
    int products;
    int plus[MAX_CNT] = {0}; 
    int minus[MAX_CNT] = {0};
    int stock[MAX_CNT] = {0};
    int plus_all = 0;
    int minus_all = 0;
    int max_id = 0;
    int max_sales = 0;
    int min_id = 0;
    int min_sales = 0;

    // 상품 개수 입력
    scanf("%d", &products);

    // 상품 별 입고수량 입력 함수 호출
    quantityInStock(products, plus, &plus_all);

    // 상품 별 출고수량 및 재고수량 입력 함수 호출
    salesQuantity(products, plus, minus, stock, &plus_all, &minus_all, &min_sales, &min_id, &max_id, &max_sales);

    // 재고 수량 출력 함수 호출
    stockQuantiiy(products, stock);

    // 총 판매량과 판매율 출력
    printf("총 판매량 : %d (판매율 %.2f%%)\n", minus_all, ((float)minus_all/plus_all)*100);

    // 가장 많이/적게 판매된 상품 정보 출력
    printf("가장 많이 판매된 상품 : ID %d, 판매량 %d\n", max_id, max_sales);
    printf("가장 적게 판매된 상품 : ID %d, 판매량 %d\n", min_id, min_sales);

    // 재고 부족 출력 함수 호출
    outOfStock(products, stock);

    return 0;
}

