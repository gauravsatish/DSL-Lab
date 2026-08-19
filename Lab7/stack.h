#define MAX_SIZE 100

#include <stdio.h>

struct Stack {
	char items[MAX_SIZE];
	int top;
};

void push(struct Stack *stack, char item) {
	if (stack->top == MAX_SIZE - 1) {
		printf("Stack Overflow\n");
		return;
	}

	stack->items[++stack->top] = item;
}

char pop(struct Stack *stack) {
	if (stack->top == -1) {
		printf("Stack underflow\n");
		return 0;
	}

	return stack->items[stack->top--];
}

char peek(struct Stack *stack) {
	if (stack->top == -1) {
		printf("Stack is empty\n");
		return 0;
	}

	return stack->items[stack->top];
}

void display(struct Stack *stack) {
	printf("Stack contents:\n");
	for (int i = stack->top; i >= 0; i--) {
		printf("%c\n", stack->items[i]);
	}
}

