#include <stdio.h>

#define MAX 5

typedef struct {
    int id;
    char name[20];
} Task;

typedef struct {
    Task tasks[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue *pq) {
    pq->front = -1;
    pq->rear = -1;
}

void enqueue(Queue *pq, Task t) {
    if (pq->rear == MAX - 1) {
        printf("Queue is full\n");
        return;
    }
    if (pq->front == -1) pq->front = 0;
    
    pq->tasks[++(pq->rear)] = t;
    printf("Enqueued Job: %s (ID: %d)\n", t.name, t.id); 
}

void dequeue(Queue *pq) {
    if (pq->front == -1 || pq->front > pq->rear) {
        printf("Queue is empty\n");
        return;
    }
    
    Task t = pq->tasks[(pq->front)++];
    printf("Printing Job: %s (ID: %d)\n", t.name, t.id);
    
    if (pq->front > pq->rear) {
        pq->front = -1;
        pq->rear = -1;
    }
}

int main() {
    Queue pq;
    initQueue(&pq);
    
    Task t1 = {101, "Doc.pdf"};
    Task t2 = {102, "Image.png"};
    
    enqueue(&pq, t1);
    enqueue(&pq, t2);
    
    dequeue(&pq);
    dequeue(&pq);
    
    dequeue(&pq);
    dequeue(&pq);
    
    return 0;
}
