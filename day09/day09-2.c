#include <stdio.h>

struct Product {
    int id;
    char goods_name[100];
    int price;
};

void printProduct(struct Product product) {
    printf("��ǰ ID : %d\n", product.id);
    printf("��ǰ�� : %s", product.goods_name);
    printf("��ǰ ���� : %d��\n\n", product.price);
}

int main() {
    struct Product products[5];
    int i = 0;

    while (i < 5) {
        printf("��ǰ ������ �Է��ϼ��� (�Է� �ߴ��� ID�� 0 �Է�)\n");
        printf("��ǰ ID: ");
        scanf_s("%d", &products[i].id);
        if (products[i].id == 0) {
            break;
        }
        printf("��ǰ��: ");
        getchar();
        fgets(products[i].goods_name, sizeof(products[i].goods_name), stdin);
        printf("��ǰ ����: ");
        scanf_s("%d", &products[i].price);
        printf("\n");
        i++;
    }

    if (i == 0) {
        printf("�Էµ� ��ǰ�� �����ϴ�.\n");
    }
    else {
        printf("\n<< �Էµ� ��ǰ ��� >>\n");
        for (int j = 0; j < i; j++) {
            printProduct(products[j]);
        }
    }

    return 0;
}
