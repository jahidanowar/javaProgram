/***
 * Doubly Linked List Implementation
 * @registeration: 2147033
 * @author: jahidanowar.mustafa@mscsa.christuniversity.in
 **/

#include <stdio.h>;
#include <stdlib.h>;

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void push(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    newNode->next = (*head);
    newNode->prev = NULL;

    if ((*head) != NULL)
    {
        (*head)->prev = newNode;
    }

    (*head) = newNode;
}

void insertAt(struct Node *node, int data)
{
    if (node == NULL)
    {
        printf("The node can not be null");
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = node->next;

    node->next = newNode;

    newNode->prev = node;

    if (newNode->next != NULL)
    {
        newNode->next->prev = newNode;
    }
}

void append(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    if ((*head) == NULL)
    {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    struct Node *tmp = *head;

    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    tmp->next = newNode;
    newNode->prev = tmp;

    return;
}

void display(struct Node **head)
{
    struct Node *tmp = *head;

    while (tmp->next != NULL)
    {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
}

int main()
{
    printf("+++ Doubly Linked List +++ \n");

    struct Node *head = NULL;

    // Menu Driven
    int choice;
    int data;

    do
    {
        printf("\n1. Push\n2. Insert At\n3. Append\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &data);
            push(&head, data);
            break;
        case 2:
            printf("Enter the data: ");
            scanf("%d", &data);
            insertAt(head, data);
            break;
        case 3:
            printf("Enter the data: ");
            scanf("%d", &data);
            append(&head, data);
            break;
        case 4:
            display(&head);
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    } while (choice != 5);

    return 0;
}