#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

// Khai bao cau truc du lieu stack
typedef struct {
    char data[MAX_STACK_SIZE];
    int top;
} Stack;

// Ham khoi tao stack
void initStack(Stack* stack) {
    stack->top = -1;
}

// Ham kiem tra stack rong
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Ham kiem tra stack day
int isFull(Stack* stack) {
    return stack->top == MAX_STACK_SIZE - 1;
}

// Ham them phan tu vao stack
void push(Stack* stack, char value) {
    if (isFull(stack)) {
        printf("Error: Stack is full\n");
        return;
    }
    stack->data[++stack->top] = value;
}

// Ham lay phan tu ra khoi stack
char pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Error: Stack is empty\n");
        return '\0';
    }
    return stack->data[stack->top--];
}

// Ham kiem tra xem mot ky tu co phai la toan tu hay khong
int isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return 1;
    return 0;
}

// Ham kiem tra xem toan tu 1 co do uu tienn cao hon toan tu 2 khong
int isHigherPrecedence(char op1, char op2) {
    if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-'))
        return 1;
    return 0;
}

// Chuyen bieu thuc infix sang postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i, j;
    Stack stack;
    initStack(&stack);
    push(&stack, '('); // Them dau ngoac trai vào stack

    i = 0;
    j = 0;
    while (infix[i] != '\0') {
        // Neuu ky tu hien tai la toan hang, them vao postfix
        if (!isOperator(infix[i]) && infix[i] != '(' && infix[i] != ')') {
            postfix[j++] = infix[i++];
        }
        // Neu ky tu hien tai la dau ngoac trai, them vào stack
        else if (infix[i] == '(') {
            push(&stack, infix[i++]);
        }
        // Neu ky tu hien tai la dau ngoac phai, lay nhung phan tu trong stack cho den khi gap dau ngoac trai
        // va them vao postfix
        else if (infix[i] == ')') {
            while (!isEmpty(&stack) && stack.data[stack.top] != '(') {
                postfix[j++] = pop(&stack);
            }
            if (!isEmpty(&stack) && stack.data[stack.top] == '(') {
                pop(&stack);
            }
            i++;
        }
        // Neu ky tu hirn tai la toan tu
        else if (isOperator(infix[i])) {
            // Lay nhung phan tu trong stack co do uu tien cao hon hoac bang toan tu hien tai
            // va them vao postfix
            while (!isEmpty(&stack) && stack.data[stack.top] != '(' && isHigherPrecedence(stack.data[stack.top], infix[i])) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, infix[i++]);
        }
    }

    // Lay nhung phan tu con lai trong stack va them vao postfix
    while (!isEmpty(&stack) && stack.data[stack.top] != '(') {
        postfix[j++] = pop(&stack);
    }
    postfix[j] = '\0';
}

int main() {
    char infix[100];
    char postfix[100];

    printf("Nhap bieu thuc infix: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strlen(infix) - 1] = '\0';

    infixToPostfix(infix, postfix);

    printf("Bieu thuc postfix tuong ung: %s\n", postfix);

    return 0;
}

