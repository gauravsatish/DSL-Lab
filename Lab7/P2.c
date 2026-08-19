#include "stack.h"
#include <stdio.h>
#include <string.h>

int main() {
	printf("Enter the expression: ");
	char str[100];
	fgets(str, 100, stdin);
	str[strcspn(str, "\n")] = '\0';

	struct Stack stack;
	stack.top = -1;
	for (int i = 0; i < strlen(str); i++) {
		switch(str[i]) {
		case '(':
		case '{':
		case '[':
			push(&stack, str[i]);
			printf("Pushed %c to stack\n", str[i]);
			break;
		case ')':
			if (peek(&stack) == '(') {
				pop(&stack);
				break;
			} else {
				printf("Unbalanced expression\n");
				return 0;
			}
		case '}':
			if (peek(&stack) == '{') {
				pop(&stack);
				break;
			} else {
				printf("Unbalanced expression\n");
				return 0;
			}
		case ']':
			if (peek(&stack) == '[') {
				pop(&stack);
				break;
			} else {
				printf("Unbalanced expression\n");
				return 0;
			}
		}
	}

	printf("Balanced expression\n");
}