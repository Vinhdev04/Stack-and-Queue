#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Khai bao Stack
 struct stack {
    int data[MAX_SIZE];  
    int top; 
};
typedef struct stack Stack; 

// Ham khoi tao Stack
void Init(Stack &s) {
    s.top = -1;  // stack rong ==. top = -1 
}

// Ham kiem tra Stack rong
bool isEmpty(Stack s) {
    return s.top == -1;
}

// Ham kiem tra Stack day
bool isFull(Stack s) {
    return s.top == MAX_SIZE - 1;
}

// Ham them phan tu vao Stack
void push(Stack &s, int value) {
    if (isFull(s)) {
        printf("Stack Full !\n");
    } else {
        s.data[++s.top] = value; // Thêm ph?n t? vào m?ng và c?p nh?t top
        printf("So %d pushed to stack.\n", value);
    }
}

// Ham xoa phan tu khoi Stack
int pop(Stack &s) {
    if (isEmpty(s)) {
        printf("Stack underflow!\n");
        return -1;
    } else {
        int value = s.data[s.top--]; // L?y giá tr? ph?n t? và gi?m top
        return value;
    }
}

// Ham lay phan tu o dau Stack (không xóa)
int peek(Stack &s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return -1;
    } else {
        return s.data[s.top];
    }
}

// Ham hien thi Stack
void display(Stack &s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack Copy: ");
        for (int i = 0; i <= s.top; i++) {
            printf("%d ", s.data[i]);
        }
        printf("\n");
    }
}

// Ham nhap danh sach so nguyen vao Stack
void inputList(Stack &s) {
    int size;
    printf("Nhap so phan tu: ");
    scanf("%d", &size);

    printf("Nhap so nguyen:\n");
    for (int i = 0; i < size; i++) {
        int value;
        scanf("%d", &value);
        push(s, value);
    }
}

// Ham xuat danh sach so nguyên tu Stack
void outputList(Stack &s) {
    printf("Stack: ");
    for (int i = s.top; i >= 0; i--) {
        printf("%d ", s.data[i]);
    }
    printf("\n");
}

// Ham copy Stack sang mot Stack khac
void copyStack(Stack &s, Stack &copy) {
    Init(copy);  // Kh?i t?o Stack copy

    for (int i = s.top; i >= 0; i--) {
        push(copy, s.data[i]); 
    }
}

int main() {
    Stack s, copy;
    Init(s);
    Init(copy);

    printf("Input list:\n");
    inputList(s);

    printf("\nOutput reversed list:\n");
    outputList(s);

    copyStack(s, copy);
    printf("\nCopy Successful \n");
    display(copy);

    return 0;
}

