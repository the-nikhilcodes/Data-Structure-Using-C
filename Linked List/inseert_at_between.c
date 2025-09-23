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

// INSERT AT BETWEEN OR INDEX LOGIC
struct Node *insertAtBetween(struct Node *head, int data , int index){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;

    while (i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next= p-> next;
    p->next = ptr;
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
    fourth->next = NULL;

     printf("Linked List before insertion\n");
    linkedListTraversal(head);
    head = insertAtBetween(head , 50, 1);
     printf("Linked List after insertion\n");
    linkedListTraversal(head);

    return 0;
}
