#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student {
	int snum;
	char name[100];
	int score;
};

int main(void) {
	int N;
	float total = 0;
	struct Student* p;
	printf("�л� �� �Է� : ");
	scanf_s("%d", &N);
	p = (struct Student*)malloc(N * sizeof(struct Student));
	for (int i = 0; i < N; i++) {
		printf("�й� : ");
		scanf_s("%d", & p[i].snum);
		printf("�̸� : ");
		scanf_s("%s", p[i].name, 100);
		printf("����: ");
		scanf_s("%d", &p[i].score);
	}
	for (int i = 0; i < N; i++) {
		printf("%d %s %d\n", p[i].snum, p[i].name, p[i].score);
		total += p[i].score;
	}
	float average = total / N;
	printf("��� : %f\n", average);
	return 0;
}