#include <stdio.h>

struct vector {
	int coordinate[3];
};

void add_vector(struct vector v1, struct vector v2);
void min_vector(struct vector v1, struct vector v2);
void out_vector(struct vector v1, struct vector v2);
void in_vector(struct vector v1, struct vector v2);

int main() {
	int order;
	struct vector vector1, vector2;
	printf("첫 번째 벡터 (x, y, z) : ");
	scanf_s("%d %d %d", &vector1.coordinate[0], &vector1.coordinate[1], &vector1.coordinate[2]);
	printf("두 번째 벡터 (x, y, z) : ");
	scanf_s("%d %d %d", &vector2.coordinate[0], &vector2.coordinate[1], &vector2.coordinate[2]);
	printf("입력된 첫 번째 벡터\t%d,\t%d,\t%d\n", vector1.coordinate[0], vector1.coordinate[1], vector1.coordinate[2]);
	printf("입력된 두 번째 벡터\t%d,\t%d,\t%d\n\n", vector2.coordinate[0], vector2.coordinate[1], vector2.coordinate[2]);
	printf("-------------------------------------\n");
	printf("1. 벡터의 합\n");
	printf("2. 벡터의 차\n");
	printf("3. 벡터의 외적\n");
	printf("4. 벡터의 내적\n");
	printf("5. 종료\n");
	printf("-------------------------------------\n");
	printf("명령 입력 : ");
	scanf_s("%d",&order);
	if (order == 1) {
		add_vector(vector1, vector2);
		printf("프로그램을 종료합니다.\n");
	}
	else if (order == 2) {
		min_vector(vector1, vector2);
		printf("프로그램을 종료합니다.\n");
	}
	else if (order == 3) {
		out_vector(vector1, vector2);
		printf("프로그램을 종료합니다.\n");
	}
	else if (order == 4) {
		in_vector(vector1, vector2);
		printf("프로그램을 종료합니다.\n");
	}
	else if (order == 5) {
		printf("프로그램을 종료합니다.\n");
	}
	printf("-------------------------------------\n");
	return 0;
}

void add_vector(struct vector v1, struct vector v2) {
	struct vector result;
	result.coordinate[0] = v1.coordinate[0] + v2.coordinate[0];
	result.coordinate[1] = v1.coordinate[1] + v2.coordinate[1];
	result.coordinate[2] = v1.coordinate[2] + v2.coordinate[2];
	printf("벡터의 합 (x, y, z) : (%d, %d, %d)\n", result.coordinate[0], result.coordinate[1], result.coordinate[2]);
}

void min_vector(struct vector v1, struct vector v2) {
	struct vector result;
	result.coordinate[0] = v1.coordinate[0] - v2.coordinate[0];
	result.coordinate[1] = v1.coordinate[1] - v2.coordinate[1];
	result.coordinate[2] = v1.coordinate[2] - v2.coordinate[2];
	printf("벡터의 차 (x, y, z) : (%d, %d, %d)\n", result.coordinate[0], result.coordinate[1], result.coordinate[2]);
}

void out_vector(struct vector v1, struct vector v2) {
	struct vector result;
	result.coordinate[0] = v1.coordinate[1] * v2.coordinate[2] - v1.coordinate[2] * v2.coordinate[1];
	result.coordinate[1] = v1.coordinate[2] * v2.coordinate[0] - v1.coordinate[0] * v2.coordinate[2];
	result.coordinate[2] = v1.coordinate[0] * v2.coordinate[1] - v1.coordinate[1] * v2.coordinate[0];
	printf("벡터의 외적:   x : %d   y : %d   z : %d\n", result.coordinate[0], result.coordinate[1], result.coordinate[2]);
}

void in_vector(struct vector v1, struct vector v2) {
	struct vector result;
	result.coordinate[0] = v1.coordinate[0] * v2.coordinate[0] + v1.coordinate[1] * v2.coordinate[1] + v1.coordinate[2] * v2.coordinate[2];
	printf("벡터의 내적 vecor1 · vector2 : %d\n", result.coordinate[0]);
}