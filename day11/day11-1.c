#include <stdio.h>
#include <math.h>

int main() {
	double a, b, c, k, result1, result2;

	printf("x^2의 계수를 입력하세요 : ");
	scanf_s("%lf", &a);
	printf("x의 계수를 입력하세요 : ");
	scanf_s("%lf", &b);
	printf("상수항의 수를 입력하세요 : ");
	scanf_s("%lf", &c);

	k = pow(b, 2) -( 4 * a * c);
	
	if (k == 0) {
		printf("\n중근 : X = %.2lf", (- b / (2 * a)));
	}
	else if (k < 0) {
		printf("\n이 근은 허근입니다.\n");
	}
	else if (k > 0) {
		result1 = (-b + sqrt(k)) / (2 * a);
		result2 = (-b - sqrt(k)) / (2 * a);
		printf("\n서로 다른 두근 : X = %.2lf\n\t\t X = %.2lf\n", result1, result2);
	}

	return 0;
}
