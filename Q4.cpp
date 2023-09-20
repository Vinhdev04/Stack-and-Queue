#include <stdio.h>
#include <stdlib.h>

// �?nh ngh?a c?u tr�c n�t
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// H�m t?o m?t n�t m?i
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// H�m th�m ph?n t? v�o h�ng �?i
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

// H�m x�a ph?n t? kh?i h�ng �?i
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

// H�m in danh s�ch h�ng �?i
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
