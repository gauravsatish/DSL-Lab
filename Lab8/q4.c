#include <stdio.h>

#define MAX 5

typedef struct {
    char name[30];
    int age;
    int priority;
} Patient;

typedef struct {
    Patient patients[MAX];
    int front;
    int rear;
} PatientQueue;

void initQueue(PatientQueue *pq) {
    pq->front = -1;
    pq->rear = -1;
}

void enqueue(PatientQueue *pq, Patient p) {
    if (pq->rear == MAX - 1) {
        printf("Clinic queue is full\n");
        return;
    }
    if (pq->front == -1) pq->front = 0;
    
    pq->patients[++(pq->rear)] = p;
    printf("Patient added: %s\n", p.name);
}

void dequeue(PatientQueue *pq) {
    if (pq->front == -1 || pq->front > pq->rear) {
        printf("No patients in queue\n");
        return;
    }
    
    Patient p = pq->patients[(pq->front)++];
    printf("Treating patient: %s\n", p.name);
    
    if (pq->front > pq->rear) {
        pq->front = -1;
        pq->rear = -1;
    }
}

int main() {
    PatientQueue pq;
    initQueue(&pq);
    
    Patient p1 = {"John Doe", 45, 1};
    Patient p2 = {"Jane Smith", 30, 2};
    
    enqueue(&pq, p1);
    enqueue(&pq, p2);
    
    dequeue(&pq);
    dequeue(&pq);
    
    return 0;
}
