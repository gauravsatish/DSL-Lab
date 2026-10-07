#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

Node* concatenate(Node* X1, Node* X2) {
    if (!X1) return X2;
    if (!X2) return X1;

    Node* tail = X1;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    tail->next = X2;
    X2->prev = tail;

    return X1; 
}

void display(Node* head) {
    while (head) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node* X1 = createNode(10);
    X1->next = createNode(20);
    X1->next->prev = X1;

    Node* X2 = createNode(30);
    X2->next = createNode(40);
    X2->next->prev = X2;

    printf("List X1: "); display(X1);
    printf("List X2: "); display(X2);

    X1 = concatenate(X1, X2);

    printf("Concatenated List: "); display(X1);

    return 0;
}
