#include <stdio.h>
#include <ctype.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int precedence(char x) {
    if (x == '^') return 3;
    if (x == '*' || x == '/') return 2;
    if (x == '+' || x == '-') return 1;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i, k = 0;

    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++) {
        
        // if operand
        if (isalnum(infix[i])) {
            postfix[k++] = infix[i];
        }
        // if '('
        else if (infix[i] == '(') {
            push(infix[i]);
        }
        // if ')'
        else if (infix[i] == ')') {
            while (stack[top] != '(') {
                postfix[k++] = pop();
            }
            pop(); // remove '('
        }
        // if operator
        else {
            while (top != -1 && precedence(peek()) >= precedence(infix[i])) {
                postfix[k++] = pop();
            }
            push(infix[i]);
        }
    }

    // pop remaining operators
    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';

    printf("%s", postfix);

    return 0;
}