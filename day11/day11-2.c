#include <stdio.h>
#include <math.h>

double function(double x) {
    return -log10(1 / x) + sin(x);
}
void integral(double a, double b, int n) {
    double k, sum, x, res;
    int i, j;
    for (i = 1; i <= n; i++) {
        int m = pow(2, i - 1);
        k = (b - a) / m;
        sum = 0;
        for (j = 1; j <= m; j++) {
            x = a + j * k;
            res = function(x);
            sum += function(x);
        }
        sum = sum * k;
        printf("����\t%d \t���� ��� : %lf\n", m, sum);
    }
}

int main() {
    double start, end;
    int n;

    printf("������ ���� ���� �Է��ϼ���: ");
    scanf_s("%lf", &start);
    printf("������ �� ���� �Է��ϼ���: ");
    scanf_s("%lf", &end);
    printf("������ �ִ� ������ �Է��ϼ��� (2^n): ");
    scanf_s("%d", &n);

    integral(start, end, n);

    return 0;
}