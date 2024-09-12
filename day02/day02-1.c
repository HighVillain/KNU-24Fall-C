#include <stdio.h>
int main(void) {
	int dustks;
	double num1, num2, result;
	printf("연산자를 선택하세요.\n");
	printf("1.�더하기ϱ� 2.빼기 3.곱하기, 4.나누기\n");
	scanf_s("%d", &dustks);
	printf("숫자1을 입력하세요\n");
	scanf_s("%lf", &num1);
	printf("숫자2를 입력하세요\n");
	scanf_s("%lf", &num2);
	if (dustks == 1) {
		result = num1 + num2;
		printf("%lf", result);
	}
	else if (dustks == 2) {
		result = num1 - num2;
		printf("%lf", result);
	}
	else if (dustks == 3) {
		result = num1 * num2;
		printf("%lf", result);
	}
	else if (dustks == 4) {
		result = num1 / num2;
		printf("%lf", result);
	}
	return 0;
}