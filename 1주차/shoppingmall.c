#include <stdio.h>
#define MAX_CNT 100

int main() {
    int products;
    int plus[MAX_CNT] = {}; 
    int minus[MAX_CNT] = {};
    int stock[MAX_CNT] = {};
    int id;

    scanf("%d", &products); // 상품 개수(종류) 입력

    for(int i = 0; i < products; i++) { // 상품 별 입고수량 입력
        scanf("%d", &plus[i]);
    }

    for(int i = 0; i < products; i++) { // 상품 별 판매수량 입력
        scanf("%d", &minus[i]);
        stock[i] = plus[i] - minus[i]; // 재고 수량 추가, 삭제
    }

    scanf("%d", &id); // id 입력

    printf("%d\n", stock[id - 1]); // 입력한 id에 해당하는 제품의 재고 수량 출력

    for(int i = 0; i < products; i++) { // 모든 상품의 재고 수량 출력
        printf("%d ", stock[i]);
    }

    return 0;
}