#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100


typedef struct {
    int data[MAX_QUEUE_SIZE];
    int front, rear;
} Queue;

// Ham khoi tao Queue
void initQueue(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Ham kiem tra Queue rong
int isEmpty(Queue* queue) {
    return queue->front == -1;
}

// Ham kiem tra Queue ðay
int isFull(Queue* queue) {
    return ((queue->rear + 1) % MAX_QUEUE_SIZE) == queue->front;
}

// Ham them phan tu vao cuoi cua Queue
void enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("\nError: Queue is full\n");
        return;
    }
    // Kiem tra xem Queue rong hay khong
    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    }
    queue->data[queue->rear] = value;
}

// Ham lay phan tu tu ðau cua Queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("\nError: Queue is empty\n");
        return -1;
    }
    int value = queue->data[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    }
    return value;
}

// Ham lay gia tri ðau cua Queue
int getFront(Queue* queue) {
    if (isEmpty(queue)) {
        printf("\nError: Queue is empty\n");
        return -1;
    }
    return queue->data[queue->front];
}

// Ham lay gia tri cuoi cua Queue
int getRear(Queue* queue) {
    if (isEmpty(queue)) {
        printf("\nError: Queue is empty\n");
        return -1;
    }
    return queue->data[queue->rear];
}

int main() {
    Queue queue;
    initQueue(&queue);

    int value;
    printf("Nhap 5 gia tri vao Queue:\n");
    for (int i = 0; i < 5; i++) {
        printf("Gia tri thu %d: ", i+1);
        scanf("%d", &value);
        enqueue(&queue, value);
    }

    printf("\nCac gia tri dau tien trong Queue:\n");
    for (int i = 0; i < 5; i++) {
        value = dequeue(&queue);
        printf("%d ", value);
    }

    printf("\n\nGia tri dau cua Queue: %d", getFront(&queue));
    printf("\nGia tri cuoi cua Queue: %d\n", getRear(&queue));

    return 0;
}

