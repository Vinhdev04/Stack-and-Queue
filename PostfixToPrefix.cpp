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

// Chuyen ðoi bieu thuc hau to sang bieu thuc tien to
void postfixToPrefix(char* postfix, char* prefix) {
    int i, j;
    int len = strlen(postfix);
    char stack[len];
    int top = -1;

    for (i = 0, j = 0; i < len; i++) {
        if (!isOperator(postfix[i])) {
            stack[++top] = postfix[i];
        } else {
            char operand1 = stack[top--];
            char operand2 = stack[top--];
            prefix[j++] = postfix[i];
            prefix[j++] = operand2;
            prefix[j++] = operand1;
            stack[++top] = prefix[j - 3];
        }
    }

    prefix[j] = '\0';
}

// Ham main
int main() {
    char postfix[100];
    char prefix[100];

    printf("Nhap vao bieu thuc hau to(Postfix): ");
    gets(postfix);

    postfixToPrefix(postfix, prefix);a

    printf("Bieu thuc tien to(Prefix): %s\n", prefix);

    return 0;
}
