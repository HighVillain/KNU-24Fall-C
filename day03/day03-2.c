#include <stdio.h>

int acc(int a);

int main() {
	int input;
	printf("����� ���丮�� �� : ");
	scanf_s("%d", &input);
	int result = acc(input);
	printf("%d", result);
	return 0;
}

int acc(int a)
{
	int result = 0;
	if (a == 0||a==1) {
		return 1;
	}
	
	result = a * acc(a - 1);

	return result;
}