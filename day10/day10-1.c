#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NameMax 50

struct Node {
	char name[NameMax];
	int score;
	struct Node* link;
};

struct Node* head;

struct Node* createNode(char*name, int score){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	strcpy_s(newNode->name, NameMax, name);
	newNode->score = score;
	newNode->link = NULL;

	return newNode;
}

struct Node* lastNode() {
	struct Node* cur = head;
	while (cur->link != NULL) {
		cur = cur->link;
	}
	return cur;
}

struct Node* findInsertNode(int score) {
	struct Node* prev = head;
	struct Node* cur = head->link;
	if (cur == NULL) return head;
	while (cur != NULL) {
		if (cur->score >= score) {
			if (cur->link == NULL) return cur;
			prev = cur;
			cur = cur->link;
		}
		else {
			return prev;
		}
	}
	return cur;
}

void insertPriorityNode(struct Node*newNode) {
	struct Node* n = findInsertNode(newNode->score);
	newNode->link = n->link;
	n->link = newNode;
}

void printNode() {
	struct Node* cur = head->link;
	printf("-------------------------\n");
	while (cur != NULL) {
		printf("%s   :    %d\n", cur->name,cur->score);
		cur = cur->link;
	}
	printf("-------------------------\n");
}

int deleteNode(char*name) {
	struct Node* prev = head;
	struct Node* cur = head->link;
	while (cur != NULL) {
		if (strcmp(name,cur->name)==0) {
			prev->link = cur->link;
			free(cur);
			return 1;
		}
		prev = cur;
		cur = cur->link;
	}
	return 0;
}

int main() {
	head = (struct Node*)malloc(sizeof(struct Node));
	head->link = NULL;

	int order;
	int iteration = 1;
	char name[NameMax];
	int score;

	while (iteration) {
		printf("1. 학생 성적 입력\n");
		printf("2. 학생 정보 제거\n");
		printf("3. 프로그램 종료\n");
		printf("명령 입력 : ");
		scanf_s("%d", &order);

		switch (order) {
		case 1:
			printf("학생 이름 : ");
			scanf_s("%s", name, NameMax);
			printf("점수 : ");
			scanf_s("%d", &score);
			insertPriorityNode(createNode(name, score));
			break;
		case 2:
			printf("삭제할 학생의 이름 : ");
			scanf_s("%s",name, NameMax);
			deleteNode(name);
			break;
		case 3:
		default:
			iteration = 0;
			break;
		}
		printNode();
	}

	return 0;
}