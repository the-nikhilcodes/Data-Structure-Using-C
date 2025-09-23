#include <stdio.h>
#include <stdlib.h> // for malloc()

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// CASE 2 - Deleting the element at a given index from the linked list 
struct Node *deleteAtIndex(struct Node *head , int index){
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i<index-1;i++){
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
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

    if (head == NULL || second == NULL || third == NULL || fourth == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1; // exit if malloc failed
    }

    // Link first and second node
    head->data = 4;
    head->next = second;

    // Link second and third node
    second->data = 3;
    second->next = third;

    // Link third and fourth node
    third->data = 8;
    third->next = fourth;

    // Terminate the list at the fourth node
    fourth->data = 1;
    fourth->next = NULL;


    printf("Linked List before deletion\n");
    linkedListTraversal(head);

    head = deleteAtIndex(head, 2); //for deleting 1st element of the linked list

     printf("Linked List after deletion\n");
    linkedListTraversal(head);

    return 0;
}
