#include <stdio.h>
#include<string.h>

void reverse_function(char* str) {
	char* start = str;
	char* end = str + strlen(str) - 1;
	if (*end == '\n') {
		*end = '\0';
		end--;
	}

	while (start < end) {
		int alphabet = *start;
		*start = *end;
		*end = alphabet;

		start++;
		end--;
	}
}

int main() {
	char str[100];
	printf("문자열을 입력하세요 : ");
	fgets(str, sizeof(str), stdin);

	reverse_function(str);
	
	printf("뒤집어진 문자열 : %s\n", str);
	return 0;
}