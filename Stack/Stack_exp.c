
#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

// Push a character onto the stack
void push(char c) {
    if (top == MAX - 1)
        printf("Stack Overflow!\n");
    else
        stack[++top] = c;
}

// Pop a character from the stack
char pop() {
    if (top == -1)
        return '\0'; // Stack is empty
    else
        return stack[top--];
}

int main() {
    char str[MAX], reversed[MAX];
    int i = 0;

    printf("Enter a string: ");
    gets(str);  // (for simplicity; in real code, use fgets)

    // Push all characters of the string to stack
    for (i = 0; str[i] != '\0'; i++)
        push(str[i]);

    // Pop all characters to get reversed string
    for (i = 0; top != -1; i++)
        reversed[i] = pop();
    reversed[i] = '\0';

    printf("Reversed string: %s\n", reversed);

    return 0;
}
