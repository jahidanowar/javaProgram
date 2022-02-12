/***
 * Linked List Implementation
 * @registeration: 2147033
 * @author: jahidanowar.mustafa@mscsa.christuniversity.in
 **/

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void append(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    if ((*head) == NULL)
    {
        newNode->next = NULL;
        *head = newNode;
        return;
    }

    struct Node *tmp = *head;

    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    tmp->next = newNode;
    newNode->next = NULL;

    return;
}

// Insert at a given position
void insertAt(struct Node **head, int data, int pos)
{
    if (pos == 0)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node *tmp = *head;
    int i = 0;

    while (tmp != NULL && i < pos - 1)
    {
        tmp = tmp->next;
        i++;
    }

    if (tmp == NULL)
    {
        printf("The position is greater than the number of nodes");
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = tmp->next;
    tmp->next = newNode;
}

// SEARCH AND DELETE A NODE FROM A SINGLY LINKED LIST
void deleteNode(struct Node **head, int data)
{

    struct Node *tmp = *head;

    if (tmp == NULL)
    {
        printf("The list is empty");
        return;
    }

    if (tmp->data == data)
    {
        *head = tmp->next;
        free(tmp);
        return;
    }

    while (tmp->next != NULL && tmp->next->data != data)
    {
        tmp = tmp->next;
    }

    if (tmp->next == NULL)
    {
        printf("The data is not found");
        return;
    }

    struct Node *tmp2 = tmp->next;
    tmp->next = tmp2->next;
    free(tmp2);
};

void display(struct Node *head)
{
    struct Node *tmp = head;

    while (tmp != NULL)
    {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }

    printf("\n");
}

void main()
{

    // Menu Driven Program
    int choice;
    struct Node *head = NULL;

    while (1)
    {
        printf("1. Insert at the end\n2. Insert at a given position\n3. Delete a node\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data: ");
            int data;
            scanf("%d", &data);
            append(&head, data);
            break;
        case 2:
            printf("Enter the data: ");
            int data;
            scanf("%d", &data);
            printf("Enter the position: ");
            int pos;
            scanf("%d", &pos);
            insertAt(&head, data, pos);
            break;
        case 3:
            printf("Enter the data: ");
            int data;
            scanf("%d", &data);
            deleteNode(&head, data);
            break;
        case 4:
            display(head);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}