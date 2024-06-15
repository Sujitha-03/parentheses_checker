#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char c) {
    if (top == MAX_SIZE-1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return '#';
    }
    return stack[top--];
}

int checkBalance(char* exp) {
    int i;
    for (i = 0; i < strlen(exp); i++) {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
            push(exp[i]);
        if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
            if (top == -1) {
                return 0;
            }
            char c = pop();
            if ((exp[i] == ')' && c != '(') ||
                (exp[i] == ']' && c != '[') ||
                (exp[i] == '}' && c != '{')) {
                return 0;
            }
        }
    }
    if (top == -1) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char exp[MAX_SIZE];
    printf("Enter an expression: ");
    scanf("%s", exp);
    if (checkBalance(exp)) {
        printf("Expression is balanced\n");
    } else {
        printf("Expression is not balanced\n");
    }
    return 0;
}
