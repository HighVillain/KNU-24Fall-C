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
        printf("구간\t%d \t적분 결과 : %lf\n", m, sum);
    }
}

int main() {
    double start, end;
    int n;

    printf("적분할 시작 값을 입력하세요: ");
    scanf_s("%lf", &start);
    printf("적분할 끝 값을 입력하세요: ");
    scanf_s("%lf", &end);
    printf("시행할 최대 구간을 입력하세요 (2^n): ");
    scanf_s("%d", &n);

    integral(start, end, n);

    return 0;
}