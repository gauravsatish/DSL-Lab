#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
    Node* tail;
} List;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertRear(List* list, int data) {
    Node* newNode = createNode(data);
    if (!list->tail) { 
        list->head = list->tail = newNode;
        return;
    }
    list->tail->next = newNode;
    newNode->prev = list->tail;
    list->tail = newNode;
}

void deleteRear(List* list) {
    if (!list->tail) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = list->tail;
    if (list->head == list->tail) { 
        list->head = list->tail = NULL;
    } else {
        list->tail = temp->prev;
        list->tail->next = NULL;
    }
    free(temp);
}

void insertAtPosition(List* list, int pos, int data) {
    if (pos < 1) return;
    
    if (pos == 1) { 
        Node* newNode = createNode(data);
        newNode->next = list->head;
        if (list->head) list->head->prev = newNode;
        list->head = newNode;
        if (!list->tail) list->tail = newNode; 
        return;
    }
    
    Node* temp = list->head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) temp = temp->next;
    
    if (!temp) {
        printf("Position out of bounds.\n");
        return;
    }
    
    Node* newNode = createNode(data);
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next) temp->next->prev = newNode;
    else list->tail = newNode; 
    
    temp->next = newNode;
}

void deleteAtPosition(List* list, int pos) {
    if (!list->head || pos < 1) return;
    
    Node* temp = list->head;
    if (pos == 1) { 
        list->head = temp->next;
        if (list->head) list->head->prev = NULL;
        else list->tail = NULL; 
        free(temp);
        return;
    }
    
    for (int i = 1; i < pos && temp != NULL; i++) temp = temp->next;
    
    if (!temp) {
        printf("Position out of bounds.\n");
        return;
    }
    
    temp->prev->next = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    else list->tail = temp->prev; 
    
    free(temp);
}

void insertAfter(List* list, int target, int data) {
    Node* temp = list->head;
    while (temp && temp->data != target) temp = temp->next;
    
    if (!temp) {
        printf("Element %d not found.\n", target);
        return;
    }
    
    Node* newNode = createNode(data);
    newNode->prev = temp;
    newNode->next = temp->next;
    
    if (temp->next) temp->next->prev = newNode;
    else list->tail = newNode; 
    
    temp->next = newNode;
}

void insertBefore(List* list, int target, int data) {
    Node* temp = list->head;
    while (temp && temp->data != target) temp = temp->next;
    
    if (!temp) {
        printf("Element %d not found.\n", target);
        return;
    }
    
    Node* newNode = createNode(data);
    newNode->next = temp;
    newNode->prev = temp->prev;
    
    if (temp->prev) temp->prev->next = newNode;
    else list->head = newNode; 
    
    temp->prev = newNode;
}

void traverseForward(List* list) {
    Node* temp = list->head;
    while (temp) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void traverseReverse(List* list) {
    Node* temp = list->tail; 
    while (temp) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main() {
    List myList = {NULL, NULL}; 
    List* list = &myList;      
    
    int choice, data, target, pos;

    while (1) {
        printf("\n1. Insert Rear\n2. Delete Rear\n3. Insert at Position\n");
        printf("4. Delete at Position\n5. Insert After\n6. Insert Before\n");
        printf("7. Traverse Forward\n8. Traverse Reverse\n9. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: "); scanf("%d", &data);
                insertRear(list, data); break;
            case 2:
                deleteRear(list); break;
            case 3:
                printf("Enter pos and data: "); scanf("%d %d", &pos, &data);
                insertAtPosition(list, pos, data); break;
            case 4:
                printf("Enter pos to delete: "); scanf("%d", &pos);
                deleteAtPosition(list, pos); break;
            case 5:
                printf("Enter target value and new data: "); scanf("%d %d", &target, &data);
                insertAfter(list, target, data); break;
            case 6:
                printf("Enter target value and new data: "); scanf("%d %d", &target, &data);
                insertBefore(list, target, data); break;
            case 7: traverseForward(list); break;
            case 8: traverseReverse(list); break;
            case 9: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
