#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Create new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 0. Append (Helper to easily populate the list)
Node* append(Node* head, int data) {
    Node* newNode = createNode(data);
    if (!head) return newNode; 
    
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}

// 1. Insert before a specified element
Node* insertBefore(Node* head, int target, int data) {
    if (!head) return head;
    
    // If target is the first node, head changes
    if (head->data == target) {
        Node* newNode = createNode(data);
        newNode->next = head;
        return newNode; 
    }
    
    Node* temp = head;
    while (temp->next && temp->next->data != target) temp = temp->next;
    
    if (temp->next) {
        Node* newNode = createNode(data);
        newNode->next = temp->next;
        temp->next = newNode;
    } else {
        printf("Element %d not found.\n", target);
    }
    return head;
}

// 2. Insert after a specified element
Node* insertAfter(Node* head, int target, int data) {
    Node* temp = head;
    while (temp && temp->data != target) temp = temp->next;
    
    if (temp) {
        Node* newNode = createNode(data);
        newNode->next = temp->next;
        temp->next = newNode;
    } else {
        printf("Element %d not found.\n", target);
    }
    return head;
}

// 3. Delete a specified element
Node* deleteNode(Node* head, int target) {
    if (!head) return head;
    
    // If deleting the first node, head changes
    if (head->data == target) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head; 
    }
    
    Node* temp = head;
    while (temp->next && temp->next->data != target) temp = temp->next;
    
    if (temp->next) {
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        free(toDelete);
    } else {
        printf("Element %d not found.\n", target);
    }
    return head;
}

// 4. Traverse and display
void display(Node* head) {
    if (!head) { 
        printf("List is empty.\n"); 
        return; 
    }
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// 5. Reverse the list
Node* reverse(Node* head) {
    Node *prev = NULL, *curr = head, *next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev; // prev becomes the new head
}

// 6. Sort the list (Bubble Sort - swapping data)
Node* sortList(Node* head) {
    if (!head) return head;
    int swapped;
    do {
        swapped = 0;
        Node* curr = head;
        while (curr->next) {
            if (curr->data > curr->next->data) {
                int temp = curr->data;
                curr->data = curr->next->data;
                curr->next->data = temp;
                swapped = 1;
            }
            curr = curr->next;
        }
    } while (swapped);
    return head;
}

// 7. Delete every alternate node
Node* deleteAlternate(Node* head) {
    Node* temp = head;
    while (temp && temp->next) {
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        free(toDelete);
        temp = temp->next;
    }
    return head;
}

// 8. Insert into a sorted list
Node* insertSorted(Node* head, int data) {
    Node* newNode = createNode(data);
    
    // Insert at beginning if list is empty or new data is smallest
    if (!head || head->data >= data) {
        newNode->next = head;
        return newNode; 
    }
    
    Node* temp = head;
    while (temp->next && temp->next->data < data) temp = temp->next;
    
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

int main() {
    Node* head = NULL;
    int choice, data, target;

    while (1) {
        printf("\n--- Linked List Operations ---\n");
        printf("0. Append node\n1. Insert Before\n2. Insert After\n");
        printf("3. Delete Element\n4. Display List\n5. Reverse List\n");
        printf("6. Sort List\n7. Delete Alternate Nodes\n");
        printf("8. Insert into Sorted List\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("Enter data to append: ");
                scanf("%d", &data);
                head = append(head, data);
                break;
            case 1:
                printf("Enter target element and new data: ");
                scanf("%d %d", &target, &data);
                head = insertBefore(head, target, data);
                break;
            case 2:
                printf("Enter target element and new data: ");
                scanf("%d %d", &target, &data);
                head = insertAfter(head, target, data);
                break;
            case 3:
                printf("Enter element to delete: ");
                scanf("%d", &target);
                head = deleteNode(head, target);
                break;
            case 4:
                display(head);
                break;
            case 5:
                head = reverse(head);
                printf("List reversed.\n");
                break;
            case 6:
                head = sortList(head);
                printf("List sorted.\n");
                break;
            case 7:
                head = deleteAlternate(head);
                printf("Alternate nodes deleted.\n");
                break;
            case 8:
                printf("Enter data to insert in sorted order: ");
                scanf("%d", &data);
                head = insertSorted(head, data);
                break;
            case 9:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
