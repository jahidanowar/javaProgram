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

/* push element to the list */
void push(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    if (*head == NULL)
    {
        newNode->next = newNode;
        *head = newNode;
        return;
    }

    newNode->next = (*head)->next;
    (*head)->next = newNode;
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

/* Display the linked list */
void printLL(struct Node *head)
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

    while (1)
    {
        printf("\n1. Append\n2. Push\n3. Delete\n4. Print\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to be appended: ");
            int data;
            scanf("%d", &data);
            append(&head, data);
            break;
        case 2:
            printf("Enter the element to be pushed: ");
            int data;
            scanf("%d", &data);
            push(&head, data);
            break;
        case 3:
            printf("Enter the element to be deleted: ");
            int data;
            scanf("%d", &data);
            delete (&head, data);
            break;
        case 4:
            printLL(head);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}