#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;

typedef struct CLL {
	Node *front;
	Node *last;
} CLL;

Node* createNode(int data) {
	Node *node = (Node*) malloc(sizeof(Node));
	if (!node) {
		printf("out of memory\n");
		exit(0);
	}
	node->data = data;
	node->next = NULL;
}

void insertEnd(CLL *cll, int data) {
	printf("Appending %d\n", data);
	Node *node = createNode(data);

	if (!cll->front && !cll->last) {
		node->next = node;
		cll->front = node;
		cll->last = node;
	} else {
		node->next = cll->front;
		cll->last->next = node;
		cll->last = node;
	}
}

void deleteFront(CLL *cll) {
	printf("Deleting front\n");
	if (!cll->front && !cll->last) {
		printf("List is empty\n");
	} else if (cll->front == cll->last) {
		free(cll->front);
		cll->front = NULL;
		cll->last = NULL;
	} else {
		cll->last->next = cll->front->next;
		free(cll->front);
		cll->front = cll->last->next;
	}
}

void deleteLast(CLL *cll) {
	printf("Deleting last\n");
	if (!cll->front && !cll->last) {
		printf("List is empty\n");
	} else if (cll->front == cll->last) {
		free(cll->front);
		cll->front = NULL;
		cll->last = NULL;
	} else {
		Node *tmp = cll->front;
		while (tmp->next != cll->last) {
			tmp = tmp->next;
		}
		tmp->next = cll->front;
		free(cll->last);
		cll->last = tmp;
	}
}

void display(CLL *cll) {
	if (!cll->front && !cll->last) {
		printf("List is empty\n");
	} else {
		Node *tmp = cll->front;
		do {
			printf("%d -> ", tmp->data);
			tmp = tmp->next;
		} while (tmp != cll->front);
		printf("back to %d\n", cll->front->data);
	}
}

int main() {
	CLL cll = {NULL, NULL};
	insertEnd(&cll, 1);
	display(&cll);
	insertEnd(&cll, 2);
	display(&cll);
	insertEnd(&cll, 3);
	display(&cll);
	insertEnd(&cll, 4);
	display(&cll);
	deleteLast(&cll);
	display(&cll);
	deleteFront(&cll);
	display(&cll);
}