/*
 * Circular Linked List;
 * @registration 2147033;
 */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

/* Append Element to the list */
void append(struct Node **head, int data)
{

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    if (*head != NULL)
    {
        (*head)->next = newNode;
        newNode->next = head;
        return;
    }

    newNode->next = *head;
    *head = newNode;
}

/* Display the linked list */
void printLL(struct Node *head)
{

    struct Node *temp = *head;

    while (temp->next != head)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{

    struct Node *head = NULL;

    append(&head, 10);
    append(&head, 12);
    append(&head, 15);
    append(&head, 20);

    printLL(head);

    return 0;
}