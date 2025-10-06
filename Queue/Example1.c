#include <stdio.h>
#include <stdlib.h>

#define SIZE 5  // Define the maximum size of the queue

int queue[SIZE];
int front = -1, rear = -1;

// Function to insert an element into the queue
void enqueue(int element) {
    if (rear == SIZE - 1) {
        printf("Queue is full! (Overflow)\n");
    } else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = element;
        printf("Inserted: %d\n", element);
    }
}

// Function to delete (remove) an element from the queue
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty! (Underflow)\n");
    } else {
        printf("Deleted: %d\n", queue[front]);
        front++;
        if (front > rear) {
            front = rear = -1; // Reset queue
        }
    }
}

// Function to see the front element of the queue
void peek() {
    if (front == -1)
        printf("Queue is empty!\n");
    else
        printf("Front element: %d\n", queue[front]);
}

// Function to display all elements of the queue
void display() {
    if (front == -1)
        printf("Queue is empty!\n");
    else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

// Main function to test queue operations
int main() {
    int choice, value;

    printf("Queue Implementation using Array in C\n");
    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
