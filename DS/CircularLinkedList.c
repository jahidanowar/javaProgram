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

/* push element to the end of the circular linkedlist */
void push(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;

    if (*head == NULL)
    {
        *head = newNode;
        newNode->next = *head;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

/* Delete element from the circular list */
void delete (struct Node **head, int data)
{
    struct Node *temp = *head;
    struct Node *prev = NULL;

    if (temp == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (temp->data == data)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp->data != data)
    {
        prev = temp;
        temp = temp->next;
        if (temp == *head)
        {
            printf("Element not found\n");
            return;
        }
    }

    prev->next = temp->next;
    free(temp);
}

/* Display the  circular linkedlist */
void display(struct Node *head)
{
    struct Node *temp = head;
    if (temp == NULL)
    {
        printf("List is empty\n");
        return;
    }
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main()
{

    /* Menu Driven Program */
    int choice;
    struct Node *head = NULL;
    int data;

    while (1)
    {
        printf("\n1. Push\n2. Delete\n3. Print\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to be pushed: ");
            scanf("%d", &data);
            push(&head, data);
            break;
        case 2:
            printf("Enter the element to be deleted: ");
            scanf("%d", &data);
            delete (&head, data);
            break;
        case 3:
            display(head);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}