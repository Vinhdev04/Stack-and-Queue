#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;


typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Ham khoi tao Queue
void initQueue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// Ham kiem tra Queue rong
int isEmpty(Queue* queue) {
    return queue->front == NULL;
}

// Ham them phan tu vao cuoi cua Queue
void enqueue(Queue* queue, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Ham lay phan tu tu ðau cua Queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("\nError: Queue is empty\n");
        return -1;
    }
    Node* temp = queue->front;
    int value = temp->data;
    queue->front = queue->front->next;
    free(temp);
    return value;
}

// Ham lay gia tri ðau cua Queue
int getFront(Queue* queue) {
    if (isEmpty(queue)) {
        printf("\nError: Queue is empty\n");
        return -1;
    }
    return queue->front->data;
}

// Ham lay gia tri cuoi cua Queue
int getRear(Queue* queue) {
    if (isEmpty(queue)) {
        printf("\nError: Queue is empty\n");
        return -1;
    }
    return queue->rear->data;
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

