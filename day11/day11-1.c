#include <stdio.h>
#include <math.h>

int main() {
	double a, b, c, k, result1, result2;

	printf("x^2�� ����� �Է��ϼ��� : ");
	scanf_s("%lf", &a);
	printf("x�� ����� �Է��ϼ��� : ");
	scanf_s("%lf", &b);
	printf("������� ���� �Է��ϼ��� : ");
	scanf_s("%lf", &c);

	k = pow(b, 2) -( 4 * a * c);
	
	if (k == 0) {
		printf("\n�߱� : X = %.2lf", (- b / (2 * a)));
	}
	else if (k < 0) {
		printf("\n�� ���� ����Դϴ�.\n");
	}
	else if (k > 0) {
		result1 = (-b + sqrt(k)) / (2 * a);
		result2 = (-b - sqrt(k)) / (2 * a);
		printf("\n���� �ٸ� �α� : X = %.2lf\n\t\t X = %.2lf\n", result1, result2);
	}

	return 0;
}
