#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NameMax 50

enum Rank {
	Bronze,
	Silver,
	Gold,
	Platinum
};

struct Node {
	char* customerName;
	enum Rank rank;
	int orderAmount;
	int point;
	struct Node* prev;
	struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(char* name, enum Rank rank, int orederAmount, int point) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->customerName = (char*)malloc(NameMax * sizeof(char));
	strcpy_s(newNode->customerName, NameMax, name);
	newNode->rank = rank;
	newNode->orderAmount = orederAmount;
	newNode->point = point;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

int compareCustomer(struct Node* a, struct Node* b) {
	if (a->rank != b->rank)
		return b->rank - a->rank;
	if (a->orderAmount != b->orderAmount)
		return b->orderAmount - a->orderAmount;
	return b->point - a->point;
}

void insertPriorityNode(struct Node* newnode) {
	if (head == NULL || compareCustomer(newnode, head) < 0) {
		newnode->next = head;
		if (head != NULL) {
			head->prev = newnode;
		}
		head = newnode;
	}
	else {
		struct Node* cur = head;
		while (cur != NULL&&compareCustomer(cur->next,newnode)<=0) {
			cur = cur->next;
		}
		newnode->next = cur->next;
		if (cur->next != NULL) {
			cur->next->prev = newnode;
		}
		cur->next = newnode;
		newnode->prev = cur;
	}
}

	
void deleteNode(char* name) {
	struct Node* cur = head;
	while (cur->next != NULL && strcmp(cur->customerName, name)) {
		cur = cur->next;
	}
	if (cur != NULL) {
		if (cur->prev != NULL) {
			cur->prev->next = cur->next;
		}
		else {
			head = cur->next;
		}
		if (cur->next != NULL) {
			cur->next->prev = cur->prev;
		}
		free(cur->customerName);
		free(cur);
	}
	else {
		printf("이 이름의 고객을 찾을 수 없습니다.\n");
	}
}

void printCustomer(){
	struct Node* cur = head;
 	printf("--------------------------------------------------------\n");
	while (cur != NULL) {
		printf("이름 : %s   등급 : %d   주문량 : %d   포인트 : %d\n", cur->customerName, cur->rank, cur->orderAmount, cur->point);
		cur = cur->next;
	}
	printf("--------------------------------------------------------\n");
}

void updateCustomer(char* name, enum Rank rank, int orderAmount, int point) {
	deleteNode(name);
	insertPriorityNode(createNode(name, rank, orderAmount, point));
}

int main() {
	char name[NameMax];
	int rank, orderAmount, point;
	int i = 1;
	int num;
	while (i) {
		printf("1. 고객 정보 입력\n");
		printf("2. 고객 삭제\n");
		printf("3. 고객 정보 수정\n");
		printf("4. 프로그램 종료\n");
		printf("실행할 번호를 선택해 주세요 : ");
		scanf_s("%d", &num);
		switch (num) {
		case 1:
			printf("고객 이름 : ");
			scanf_s("%s", name,NameMax);
			printf("고객 등급 (0 (Bronze), 1 (Silver), 2(Gold), 3 (Platinum) : ");
			scanf_s("%d", &rank);
			printf("주문량 : ");
			scanf_s("%d", &orderAmount);
			printf("포인트 : ");
			scanf_s("%d", &point);
			insertPriorityNode(createNode(name,rank,orderAmount,point));
			break;
		case 2:
			printf("삭제할 고객 이름 : ");
			scanf_s("%s", name,NameMax);
			deleteNode(name);
			break;
		case 3:
			printf("수정할 고객 이름 : ");
			scanf_s("%s", name,NameMax);
			printf("수정할 등급 : ");
			scanf_s("%d", &rank);
			printf("수정할 주문량 : ");
			scanf_s("%d", &orderAmount);
			printf("수정할 포인트 : ");
			scanf_s("%d", &point);
			updateCustomer(name,rank,orderAmount,point);
			break;
		case 4:
			printf("프로그램을 종료합니다.\n");
			i = 0;
			break;
		}
		printCustomer();
	}
	return 0;
}