#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Ki?m tra xem m?t k? t? c� ph?i l� to�n t? hay kh�ng
int isOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
        return 1;
    }
    return 0;
}

// Th?c hi?n ph�p t�nh gi?a hai s? v?i m?t to�n t?
int performOperation(int operand1, int operand2, char operator) {
    if (operator == '+') {
        return operand1 + operand2;
    } else if (operator == '-') {
        return operand1 - operand2;
    } else if (operator == '*') {
        return operand1 * operand2;
    } else if (operator == '/') {
        return operand1 / operand2;
    }
    return 0;
}

// T�nh gi� tr? c?a bi?u th?c ti?n t?
int evaluatePrefix(char* prefix) {
    int i;
    int len = strlen(prefix);
    int stack[MAX_SIZE];
    int top = -1;

    // Duy?t t? ph?i sang tr�i
    for (i = len - 1; i >= 0; i--) {
        if (prefix[i] == ' ') {
            continue;
        } else if (isdigit(prefix[i])) { // K? t? l� s?
            int operand = 0;
            int j = i;
            while (j >= 0 && isdigit(prefix[j])) {
                operand = (operand * 10) + (prefix[j] - '0');
                j--;
            }
            i = j + 1; // C?p nh?t l?i v? tr� i

            stack[++top] = operand;
        } else if (isOperator(prefix[i])) { // K? t? l� to�n t?
            int operand1 = stack[top--];
            int operand2 = stack[top--];
            int result = performOperation(operand1, operand2, prefix[i]);
            stack[++top] = result;
        }
    }

    return stack[top];
}

// H�m main
int main() {
    char prefix[MAX_SIZE];

    printf("Nhap vao bieu thuc tien to: ");
    fgets(prefix, MAX_SIZE, stdin);
    prefix[strlen(prefix) - 1] = '\0'; // X�a k? t? newline

    int result = evaluatePrefix(prefix);

    printf("Gia tri cua bieu thuc tien to: %d\n", result);

    return 0;
}
