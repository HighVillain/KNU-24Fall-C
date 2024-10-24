#include <stdio.h>

struct Product {
    int id;
    char goods_name[100];
    int price;
};

void printProduct(struct Product product) {
    printf("상품 ID : %d\n", product.id);
    printf("상품명 : %s", product.goods_name);
    printf("상품 가격 : %d원\n\n", product.price);
}

int main() {
    struct Product products[5];
    int i = 0;

    while (i < 5) {
        printf("상품 정보를 입력하세요 (입력 중단은 ID에 0 입력)\n");
        printf("상품 ID: ");
        scanf_s("%d", &products[i].id);
        if (products[i].id == 0) {
            break;
        }
        printf("상품명: ");
        getchar();
        fgets(products[i].goods_name, sizeof(products[i].goods_name), stdin);
        printf("상품 가격: ");
        scanf_s("%d", &products[i].price);
        printf("\n");
        i++;
    }

    if (i == 0) {
        printf("입력된 상품이 없습니다.\n");
    }
    else {
        printf("\n<< 입력된 상품 목록 >>\n");
        for (int j = 0; j < i; j++) {
            printProduct(products[j]);
        }
    }

    return 0;
}
