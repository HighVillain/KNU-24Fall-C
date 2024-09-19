#include <stdio.h>

int is_prime_number(int a);

int main(void) {
	int input;
	printf("소수인지 확인할 수를 입력하세요 : ");
	scanf_s("%d", &input);
	int result = is_prime_number(input);
	printf("result = %d\n", result);
	return 0;
}

int is_prime_number(int a)
{
	for (int i = 2; i < a; i++) {
		if (a % i == 0) {
			return 0;
		}
	}
	return 1;
}