#include <stdio.h>
#include <stdlib.h>

// Ð?nh ngh?a c?u trúc nút
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Hàm t?o m?t nút m?i
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Hàm thêm ph?n t? vào hàng ð?i
void enqueue(Node** front, Node** rear, int value) {
    Node* newNode = createNode(value);
    if (*rear == NULL) {
        *front = *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
    printf("Added element: %d\n", value);
}

// Hàm xóa ph?n t? kh?i hàng ð?i
void dequeue(Node** front, Node** rear) {
    if (*front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    Node* temp = *front;
    *front = (*front)->next;
    if (*front == NULL) {
        *rear = NULL;
    }
    printf("Removed element: %d\n", temp->data);
    free(temp);
}

// Hàm in danh sách hàng ð?i
void printQueue(Node* front) {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    while (front != NULL) {
        printf("%d ", front->data);
        front = front->next;
    }
    printf("\n");
}

int main() {
    Node* front = NULL;
    Node* rear = NULL;

    enqueue(&front, &rear, 1);
    enqueue(&front, &rear, 2);
    enqueue(&front, &rear, 3);
    printQueue(front);

    dequeue(&front, &rear);
    printQueue(front);

    dequeue(&front, &rear);
    printQueue(front);

    dequeue(&front, &rear);
    printQueue(front);

    return 0;
}
