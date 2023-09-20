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

// Kiem tra do uu tien cua cac toan 
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

// Dao nguoc mot chuoi
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

// Chuyen doi bieu thuc trung to sang bieu thuc tien to
void infixToPrefix(char* infix, char* prefix) {
    int i, j;
    int len = strlen(infix);
    char stack[len];
    int top = -1;

    // Ðao nguoc chuoi bieu thuc trung toto
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

    // Ðao nguoc chuoi bieu thuc tien to ket qua
    reverseString(prefix);
}

// Ham main
int main() {
    char infix[100];
    char prefix[100];

    printf("Nhap vao bieu thuc trung to(Infix): ");
    gets(infix);

    infixToPrefix(infix, prefix);

    printf("Bieu thuc tien to(Prefix): %s\n", prefix);

    return 0;
}
