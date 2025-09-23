#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

// Traversal of a circular doubly linked list
void linkedListTraversal(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *ptr = head;
    do
    {
        printf(" Element is %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Assign values and link nodes
    head->data = 7;
    head->next = second;
    head->prev = fourth;   // circular link to last node

    second->data = 11;
    second->next = third;
    second->prev = head;

    third->data = 66;
    third->next = fourth;
    third->prev = second;

    fourth->data = 99;
    fourth->next = head;   // circular link back to head
    fourth->prev = third;

    // Traversal
    linkedListTraversal(head);

    return 0;
}
