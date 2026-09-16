#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
} Node;

typedef struct SLL {
	Node *head;
} SLL;

Node* createNode(int data) {
	Node *node = (Node *) malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;

	return node;
}

void createSLL(SLL *sll) {
	sll->head = NULL;
}

void insertBefore(SLL *sll, int b, int e) {
	Node *node = createNode(e);

	if (sll->head == NULL) {
		sll->head = node;
		return;
	}

	if(sll->head->data == b) {
		node->next = sll->head;
		sll->head = node;
		return;
	}

	Node *temp = sll->head;
	while (temp->next != NULL && temp->next->data != b) {
		temp = temp->next;
	}
	node->next = temp->next;
	temp->next = node;
}

void insertAfter(SLL *sll, int a, int e) {
	Node *node = createNode(e);

	if(sll->head == NULL) {
		sll->head = node;
		return;
	}

	Node *temp = sll->head;
	while (temp->next != NULL) {
		if (temp->data == a) break;
		temp = temp->next;
	}
	
	node->next = temp->next;
	temp->next = node;
}

void delete(SLL *sll, int e) {
	// Added a safety check for empty list to prevent crash
	if (sll->head == NULL) {
		printf("List is empty. Nothing to delete.\n");
		return;
	}

	Node *temp = sll->head;
	Node *del = sll->head;

	if (sll->head->data == e) {
		del = sll->head;
		sll->head = sll->head->next;
		free(del);
		return;
	}

	while (temp->next != NULL) {
		if (temp->next->data == e) {
			if (temp->next->next == NULL) {
				free(temp->next);
				temp->next = NULL;
				break;
			} else {
				del = temp->next;
				temp->next = temp->next->next;
				free(del);
				break;
			}
		}
		temp = temp->next;
	}
}

void displaySLL(SLL *sll) {
	Node *temp = sll->head;
	if (temp == NULL) {
		printf("List is empty.\n");
		return;
	}
	while (temp != NULL) {
		printf("%d, ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void sort(SLL *sll) {
	Node *head = sll->head;
	while (head != NULL) {
		Node *low = head;
		Node *tmp = head;
		while (tmp != NULL) {
			if (tmp->data < low->data) {
				low = tmp;
			}
			tmp = tmp->next;
		}

		int a = head->data;
		head->data = low->data;
		low->data = a;

		head = head->next;
	}
}

void deleteAlt(SLL *sll) {
	Node *temp = sll->head;
	Node *del = sll->head;
	
	while (temp != NULL && temp->next != NULL) {
		if (temp->next->next == NULL) {
			free(temp->next);
			temp->next = NULL;
		} else {
			del = temp->next;
			temp->next = temp->next->next;
			free(del);
		}
		temp = temp->next;
	}
}

void insertSorted(SLL *sll, int e) {
	Node *node = createNode(e);
	if (sll->head == NULL) {
		sll->head = node;
		return;
	}

	Node *temp = sll->head;

	if (e <= sll->head->data) {
		node->next = sll->head;
		sll->head = node;
		return;
	}

	while(temp != NULL) {
		if (e >= temp->data) {
			if (temp->next == NULL) {
				temp->next = node;
				break;
			}
			if (e <= temp->next->data) {
				node->next = temp->next;
				temp->next = node;
				break;
			}
		}
		temp = temp->next;
	}
}

void reverse(SLL *sll) {
	Node *prev = NULL;
    Node *current = sll->head;
    Node *next = NULL;

    while (current != NULL) {
        next = current->next;    
        current->next = prev;    
        
        prev = current;          
        current = next;          
    }

    sll->head = prev; 
}

int main() {
	SLL sll;
	createSLL(&sll);
	int choice, val, target;

	while (1) {
		printf("\n=== SINGLY LINKED LIST MENU ===\n");
		printf("1. Insert Before Element\n");
		printf("2. Insert After Element\n");
		printf("3. Insert Sorted\n");
		printf("4. Delete Specific Element\n");
		printf("5. Delete Alternate Elements\n");
		printf("6. Sort List\n");
		printf("7. Reverse List\n");
		printf("8. Display List\n");
		printf("9. Exit\n");
		printf("Enter choice (1-9): ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				printf("Enter target element (b): ");
				scanf("%d", &target);
				printf("Enter element to insert (e): ");
				scanf("%d", &val);
				insertBefore(&sll, target, val);
				break;
			case 2:
				printf("Enter target element (a): ");
				scanf("%d", &target);
				printf("Enter element to insert (e): ");
				scanf("%d", &val);
				insertAfter(&sll, target, val);
				break;
			case 3:
				printf("Enter element to insert in sorted order: ");
				scanf("%d", &val);
				insertSorted(&sll, val);
				break;
			case 4:
				printf("Enter element to delete: ");
				scanf("%d", &val);
				delete(&sll, val);
				break;
			case 5:
				printf("Deleting alternate elements...\n");
				deleteAlt(&sll);
				break;
			case 6:
				printf("Sorting the list...\n");
				sort(&sll);
				break;
			case 7:
				printf("Reversing the list...\n");
				reverse(&sll);
				break;
			case 8:
				printf("List Elements: ");
				displaySLL(&sll);
				break;
			case 9:
				printf("Exiting program.\n");
				exit(0);
			default:
				printf("Invalid option! Please enter a choice between 1 and 9.\n");
		}
	}
	return 0;
}
