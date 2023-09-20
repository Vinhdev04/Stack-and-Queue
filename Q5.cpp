#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    int priority;
    struct Node* next;
    struct Node* prev;
} Node;


Node* createNode(int value, int priority) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->priority = priority;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}


void enqueue(Node** front ,Node** rear, int value, int priority) {
    Node* newNode = createNode(value, priority);
    if (*front == NULL) {
        *front = *rear = newNode;
    } else if (priority < (*front)->priority) {
        newNode->next = *front;
        (*front)->prev = newNode;
        *front = newNode;
    } else {
        Node* temp = *front;
        while (temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        } else {
            *rear = newNode;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Added element: %d with priority %d\n", value, priority);
}

void dequeue(Node** front, Node** rear) {
    if (*front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    Node* temp = *front;
    *front = (*front)->next;
    if (*front != NULL) {
        (*front)->prev = NULL;
    } else {
        *rear = NULL;
    }
    printf("Removed element: %d with priority %d\n", temp->data, temp->priority);
    free(temp);
}


void printQueue(Node* front) {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    while (front != NULL) {
        printf("%d (priority: %d) ", front->data, front->priority);
        front = front->next;
    }
    printf("\n");
}

int main() {
    Node* front = NULL;
    Node* rear = NULL;

    enqueue(&front, &rear, 1, 2);
    enqueue(&front, &rear, 2, 1);
    enqueue(&front, &rear, 3, 3);
    printQueue(front);

    dequeue(&front, &rear);
    printQueue(front);

    dequeue(&front, &rear);
    printQueue(front);

    dequeue(&front, &rear);
    printQueue(front);

    return 0;
}

