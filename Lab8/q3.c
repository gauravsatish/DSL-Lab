#include <stdio.h>

#define MAX 5

typedef struct {
    int data[MAX];
    int front;
    int rear;
} SQ;

void initQ(SQ *q) {
    q->front = -1;
    q->rear = -1;
}

void enqueue(SQ *q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    
    q->data[++(q->rear)] = value;
    printf("Added %d\n", value);
}

void dequeue(SQ *q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue Underflow\n");
        return;
    }
    
    int value = q->data[(q->front)++];
    printf("Removed %d\n", value);
    
    if (q->front > q->rear) {
        q->front = -1;
        q->rear = -1;
    }
}

int main() {
    SQ q;
    initQ(&q);
    
    enqueue(&q, 5);
    enqueue(&q, 15);
    dequeue(&q);
    
    return 0;
}
