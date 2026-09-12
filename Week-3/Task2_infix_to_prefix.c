#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

int precedence(char ch) {
    if(ch == '^')
        return 3;
    if(ch == '*' || ch == '/')
        return 2;
    if(ch == '+' || ch == '-')
        return 1;
    return 0;
}

void reverse(char str[]) {
    int i, j;
    char temp;

    for(i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main() {
    char infix[100], postfix[100], prefix[100];
    int i, j = 0;
    char ch;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    reverse(infix);

    for(i = 0; infix[i] != '\0'; i++) {
        if(infix[i] == '(')
            infix[i] = ')';
        else if(infix[i] == ')')
            infix[i] = '(';
    }

    top = -1;

    for(i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        if(isalnum(ch)) {
            postfix[j++] = ch;
        }
        else if(ch == '(') {
            push(ch);
        }
        else if(ch == ')') {
            while(top != -1 && stack[top] != '(')
                postfix[j++] = pop();

            pop();
        }
        else {
            while(top != -1 && precedence(stack[top]) > precedence(ch))
                postfix[j++] = pop();

            push(ch);
        }
    }

    while(top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';

    reverse(postfix);

    strcpy(prefix, postfix);

    printf("Prefix expression: %s", prefix);

    return 0;
}