#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
	double x = 0;
	double y = 0;
	int circle = 0;
	double pi = 1.0;

	srand(time(NULL));

	for (int i = 0; i < 1000000000; i++) {
		x = (double)rand() / (double)RAND_MAX;
		y = (double)rand() / (double)RAND_MAX;
		if (sqrt(x * x + y * y) < 1) {
			circle++;
		}
		pi = 4.0 * (double)circle / (double)i;

		if (i % 10000000 == 0) {
			int percent = i / 10000000;
			printf("%2.d%% 진행 . . 원주율 : %lf", percent, pi);
			for (int j = 0; j < percent / 5; j++) {
				printf("■");
			}
			for (int j = 0; j < 20 - percent / 5; j++) {
				printf("□");
			}
			printf("\n");
		}
	}
	printf("원주율 : %lf\n", pi);
	return 0;
}