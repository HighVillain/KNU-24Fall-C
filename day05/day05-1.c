#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int N;
	int* snum;
	int* score;
	char** name;
	int total = 0;
	
	printf("�л� ���� �Է��� �ּ��� : ");
	scanf_s("%d", &N);
	snum = (int*)malloc(N * sizeof(int));
	score = (int*)malloc(N * sizeof(int));
	name = (char**)malloc(N * sizeof(char*));
	for (int i = 0; i < N; i++) {
		name[i] = (char*)malloc(100 * sizeof(char));
	}
	for (int i = 0; i < N; i++) {
		printf("�й� : ");
		scanf_s("%d", &snum[i]);
		printf("�̸� : ");
		scanf_s("%s", name[i], 100);
		printf("����: ");
		scanf_s("%d", &score[i]);
	}

	for (int i = 0; i < N; i++) {
		printf("%d %s %d\n", snum[i], name[i], score[i]);
	}

	
	for (int i = 0; i < N; i++) {
		total += score[i];
	}
	int average = total / N;
	printf("��� ���� : %d\n", average);

	free(snum);
	snum = NULL;
	free(score);
	score = NULL;
	for (int i = 0; i < N; i++) {
		free(name[i]);
	}
	free(name);
	name = NULL;

	return 0;
}