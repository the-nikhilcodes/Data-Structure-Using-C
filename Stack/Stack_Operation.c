#include<stdio.h>
#include<stdlib.h>
#define MAX 5 // Maximum size of  Stack

int stack[ MAX];  // Array to hold stack elements
int top = -1;      // Initialize stack as empty

// Function to check if stack is full 
int isFull(){
    return (top == MAX- 1);
} 

// Function to check if stack is Empty
int isEmpty(){
    return (top == -1);
}

//Push Operation
void push(int value){
    if (isFull()){
        printf("Stack Overflow! cannot push %d\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("Pushed %d into the Stack.\n", value);
    } 
}

//Pop Operation
void pop(){
    if (isEmpty()){
        printf("Stack Underflow! Nothing to pop.\n");
    } else {
        printf("Popped %d from stack. \n", stack[top]);
        top--;
    }
}

// Display Stack 
void display(){
    if (isEmpty()){
        printf("Stack is Empty.\n");
    } else {
        printf("Stack Element : ");
        for (int i = top; i>= 0; i--){
            printf("\n%d" , stack[i]);
        }
        printf("\n");
    }
}

// MAIN FUNCTION
int main (){
    push(10);
    push(20);
    push(30);
    display();

    pop();
    display();

    push(40);
    push(50);
    push(60);  // Overflow Because MAX = 5 Element only 
    display();

    return 0;
}
