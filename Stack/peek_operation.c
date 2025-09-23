#include <stdio.h>
#define MAX 5   // Maximum size of stack

int stack[MAX];
int top = -1;  // Initially stack is empty

// Function to push element into stack
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        stack[++top] = value;
        printf("%d pushed into stack.\n", value);
    }
}

// Function to pop element from stack
int pop() {
    if (top == -1) {
        printf("Stack Underflow! No element to pop.\n");
        return -1;
    } else {
        return stack[top--];
    }
}

// Function to peek top element of stack
int peek() {
    if (top == -1) {
        printf("Stack is empty! Nothing to peek.\n");
        return -1;
    } else {
        return stack[top];
    }
}

// Function to display stack elements
void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    push(10);
    push(20);
    push(30);

    display();

    printf("Peek element: %d\n", peek());  // Should show 30 (top element)

    printf("Popped element: %d\n", pop());
    printf("Peek element after pop: %d\n", peek());

    display();

    return 0;
}
