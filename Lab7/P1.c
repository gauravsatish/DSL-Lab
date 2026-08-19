#include "stack.h"
#include <stdio.h>
#include <string.h>

int main() {
	struct Stack stack;
	stack.top = -1;

	char str[100];
	printf("Enter a string: ");
	fgets(str, 100, stdin);

	str[strcspn(str, "\n")] = '\0';

	for (int i = 0; i < strlen(str); i++) {
		push(&stack, str[i]);
	}

	display(&stack);

	char rev[100];
	int i = 0;
	for (; i < strlen(str); i++) {
		rev[i] = pop(&stack);
	}
	rev[i] = '\0';

	printf("Original: %s\n", str);
	printf("Reverse: %s\n", rev);

	if (strcmp(str, rev) == 0) {
		printf("The strings are palindrome\n");
	} else {
		printf("The strings are not palindrome\n");
	}
}