#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 10

void fill_rand_num(int array[size][size]);
void print_array(int array[size][size]);
void move_pointer(void* array);

int main() {
	int array[size][size];

	fill_rand_num(array);
	print_array(array);
	move_pointer(array);
	return 0;
}

void fill_rand_num(int array[size][size]) {
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			array[i][j] = (rand() % 20 + 1);
		}
	}
}

void print_array(int array[size][size]) {
	printf("배열 출력 : ");
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (j == 0) {
				printf("\n");
			}
			printf("%d ", array[i][j]);
		}
	}
	printf("\n");
}

void move_pointer(void* array){
	void* target;
	int value;
	int n = 0;
	while (1) {
		target = ((int*)array + n);
		value = *(int*)target;
		int n1 = n / 10;
		int n2 = n % 10;
		printf("현재 위치 : (%d, %d), 배열의 값 : %d\n", n1, n2, value);
		n += value;
		if (n >= 100) {
			n -= value;
			printf("더 이상 이동할 수 없습니다.\n");
			printf("종료 위치 : (%d, %d), 배열의 값 : %d", n1, n2, value);
			break;
		}
	}
}