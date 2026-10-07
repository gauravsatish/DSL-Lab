#include <stdio.h>

#define MAX 5

typedef struct {
    int items[MAX];
    int front;
    int rear;
} CQ;

void initQ(CQ *cq) {
    cq->front = 0;
    cq->rear = 0;
}

int isFull(CQ *cq) {
    return ((cq->rear + 1) % MAX == cq->front);
}

int isEmpty(CQ *cq) {
    return (cq->front == cq->rear);
}

void enqueue(CQ *cq, int item) {
    if (isFull(cq)) {
        printf("Queue is full\n");
        return;
    }
    cq->rear = (cq->rear + 1) % MAX;
    cq->items[cq->rear] = item;
    printf("Enqueued: %d\n", item);
}

void dequeue(CQ *cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty\n");
        return;
    }
    cq->front = (cq->front + 1) % MAX;
    printf("Dequeued: %d\n", cq->items[cq->front]);
}

void display(CQ *cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = (cq->front + 1) % MAX;
    while (i != (cq->rear + 1) % MAX) {
        printf("%d ", cq->items[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    CQ cq;
    initQ(&cq);
    
    enqueue(&cq, 10);
    enqueue(&cq, 20);
    enqueue(&cq, 30);
    
    dequeue(&cq);
    
    enqueue(&cq, 40);
    enqueue(&cq, 50);
    enqueue(&cq, 60);
    
    display(&cq);
    return 0;
}
