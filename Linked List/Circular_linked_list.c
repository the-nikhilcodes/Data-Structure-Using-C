#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *head)
{
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

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second node
    head->data = 7;
    head->next = second;

    // Link second and third node
    second->data = 11;
    second->next = third;

    // Link third and fourth node
    third->data = 66;
    third->next = fourth;

    // Terminate the list at the fourth node
    fourth->data = 99;
    fourth->next = head;

    linkedListTraversal(head);
    return 0;
}