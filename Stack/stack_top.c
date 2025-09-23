#define MAX 5
int stack[MAX];
int top = -1;  // empty stack

// Push operation
void push(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = x; // increment top then insert
    }
}

// Pop operation
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[top--]; // return then decrement
    }
}
