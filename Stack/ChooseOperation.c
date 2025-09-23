#include <stdio.h>
#include <stdlib.h>

// Stack structure
struct stack {
    int size;
    int top;
    int *arr;
};

// Check if empty
int isEmpty(struct stack *s) {
    return (s->top == -1);
}

// Check if full
int isFull(struct stack *s) {
    return (s->top == s->size - 1);
}

// Push operation
void push(struct stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        s->top++;
        s->arr[s->top] = value;
        printf("Pushed %d into stack.\n", value);
    }
}

// Pop operation
void pop(struct stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Nothing to pop.\n");
    } else {
        printf("Popped %d from stack.\n", s->arr[s->top]);
        s->top--;
    }
}

// Peek operation
void peek(struct stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty! No top element.\n");
    } else {
        printf("Top element is: %d\n", s->arr[s->top]);
    }
}

// Display stack
void display(struct stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = s->top; i >= 0; i--) {
            printf("%d ", s->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    int choice, value;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(s, value);
                break;
            case 2:
                pop(s);
                break;
            case 3:
                peek(s);
                break;
            case 4:
                display(s);
                break;
            case 5:
                printf("Exiting program...\n");
                free(s->arr);
                free(s);
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
