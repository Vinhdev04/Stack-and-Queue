#include <stdio.h>
#include <stdlib.h>

// Khai bao cau truc Node
typedef struct Node {
    int data;           
    struct Node* next;  
} Node;

// Khai bao cau truc Stack
typedef struct {
    Node* top;  
} Stack;

// Ham khoi tao Stack
void initialize(Stack* stack) {
    stack->top = NULL;  // Ban dau Stack rong, top duoc gan gia tri NULL
}

// Ham kiem tra Stack rong
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Ham tao mot Node moi
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Ham them phan tu vao Stack
void push(Stack* stack, int value) {
    Node* newNode = createNode(value);
    newNode->next = stack->top;  // Gan next cua newNode bang top (Node dau tien hien thi)
    stack->top = newNode;        // Gan top bang newNode
    printf("Element %d pushed to stack.\n", value);
}

// Ham xoa phan tu khoi Stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        return -1;
    } else {
        Node* temp = stack->top;  // Luu Node dau tien hien thi vao bien tem temp
        int value = temp->data;   // Lay gia tri du lieu cua Node
        stack->top = temp->next;  // Gan top bang Node tiep theo cua temp
        free(temp);               // Giai phong bo nho cho temp (Node da bi xoa)
        return value;
    }
}

// Ham lay phan tu o dau Stack (khong xoa)
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return -1;
    } else {
        return stack->top->data;
    }
}

// Hàm hi?n th? Stack
void display(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements: ");
        Node* current = stack->top;  // Con tro current de duyet qua cac Node trong Stack
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

// Ham nhap danh sach so nguyen vao Stack
void inputList(Stack* stack) {
    int size;
    printf("Enter the size of the list: ");
    scanf("%d", &size);

    printf("Enter the elements of the list:\n");
    for (int i = 0; i < size; i++) {
        int value;
        scanf("%d", &value);
        push(stack, value);
    }
}

// Ham xuat danh sach so nguyen tu Stack
void outputList(Stack* stack) {
    printf("List elements: ");
    Node* current = stack->top;  // Con tro current de duyet qua cac Node trong Stack
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Ham copy Stack sang mot Stack khác
void copyStack(Stack* stack, Stack* copy) {
    initialize(copy);  // Khoi tao Stack copy

    if (isEmpty(stack)) {
        printf("Stack is empty. Nothing to copy!\n");
    } else {
        Node* current = stack->top;  // Con tro current de duyet qua cac Node trong Stack
        while (current != NULL) {
            push(copy, current->data);  // Them tung phan tu cua stack vào stack copy
            current = current->next;
        }
    }
}

int main() {
    Stack stack, copy;
    initialize(&stack);
    initialize(&copy);

    printf("Input list:\n");
    inputList(&stack);

    printf("\nOutput list:\n");
    outputList(&stack);

    copyStack(&stack, &copy);
    printf("\nCopied stack:\n");
    display(&copy);

    return 0;
}

