#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ki?m tra xem m?t k? t? có ph?i là toán t? hay không
int isOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
        return 1;
    }
    return 0;
}

// Ki?m tra xem m?t k? t? có ph?i là d?u ngo?c hay không
int isParenthesis(char ch) {
    if (ch == '(' || ch == ')') {
        return 1;
    }
    return 0;
}

// Ki?m tra ð? ýu tiên c?a các toán t?
int precedence(char ch) {
    if (ch == '^') {
        return 3;
    } else if (ch == '*' || ch == '/') {
        return 2;
    } else if (ch == '+' || ch == '-') {
        return 1;
    } else {
        return 0;
    }
}

// Ð?o ngý?c m?t chu?i
void reverseString(char* str) {
    int len = strlen(str);
    int i, j;
    char temp;

    for (i = 0, j = len - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Chuy?n ð?i bi?u th?c trung t? sang bi?u th?c ti?n t?
void infixToPrefix(char* infix, char* prefix) {
    int i, j;
    int len = strlen(infix);
    char stack[len];
    int top = -1;

    // Ð?o ngý?c chu?i bi?u th?c trung t?
    reverseString(infix);

    for (i = 0, j = 0; i < len; i++) {
        if (!isOperator(infix[i]) && !isParenthesis(infix[i])) {
            prefix[j++] = infix[i];
        } else if (isOperator(infix[i])) {
            while (top >= 0 && precedence(stack[top]) >= precedence(infix[i])) {
                prefix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
        } else if (infix[i] == ')') {
            stack[++top] = infix[i];
        } else if (infix[i] == '(') {
            while (top >= 0 && stack[top] != ')') {
                prefix[j++] = stack[top--];
            }
            top--; // Lo?i b? d?u ngo?c ')' kh?i stack
        }
    }

    while (top >= 0) {
        prefix[j++] = stack[top--];
    }

    prefix[j] = '\0';

    // Ð?o ngý?c chu?i bi?u th?c ti?n t? k?t qu?
    reverseString(prefix);
}

// Hàm main
int main() {
    char infix[100];
    char prefix[100];

    printf("Nhap vao bieu thuc trung to: ");
    gets(infix);

    infixToPrefix(infix, prefix);

    printf("Bieu thuc tien to tuong ung: %s\n", prefix);

    return 0;
}
