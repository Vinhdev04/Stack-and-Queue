#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Kiem tra xem mot ky tu co phai la toan tu hay khong
int isOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
        return 1;
    }
    return 0;
}

// Kiem tra xem mot ky tu co phai la dau ngoac hay khong
int isParenthesis(char ch) {
    if (ch == '(' || ch == ')') {
        return 1;
    }
    return 0;
}

// Kiem tra xem mot toan tu co uu tien cao hon toan tu khac hay khong
int isHigherPrecedence(char op1, char op2) {
    if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-')) {
        return 1;
    }
    if ((op1 == '^') && (op2 == '+' || op2 == '-' || op2 == '*' || op2 == '/')) {
        return 1;
    }
    return 0;
}

// Chuyen doi bieu thuc trung to sang bieu thuc hau to
void infixToPostfix(char* infix, char* postfix) {
    int i, j;
    int len = strlen(infix);
    char stack[len];
    int top = -1;

    for (i = 0, j = 0; i < len; i++) {
        if (!isOperator(infix[i]) && !isParenthesis(infix[i])) {
            postfix[j++] = infix[i];
        } else if (isOperator(infix[i])) {
            while (top >= 0 && stack[top] != '(' && isHigherPrecedence(stack[top], infix[i])) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
        } else if (infix[i] == '(') {
            stack[++top] = infix[i];
        } else if (infix[i] == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            top--; // Lo?i b? d?u m? ngo?c '(' kh?i stack
        }
    }

    while (top >= 0) {
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0';
}

// Ham main
int main() {
    char infix[100];
    char postfix[100];

    printf("Nhap vao bieu thuc Trung to (Infix): ");
    gets(infix);

    infixToPostfix(infix, postfix);

    printf("Bieu thuc Hau to (Postfix): %s\n", postfix);

    return 0;
}
