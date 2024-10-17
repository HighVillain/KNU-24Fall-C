#include <stdio.h>

int main() {
	int num = 5;
	for (int i = 0; i < num; i++) {
		for (int j = i; j <num-1; j++) {
			printf(" ");
		}
		for (int k = 0; k<i*2+1; k++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
