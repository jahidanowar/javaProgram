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

    push(&head, 10);
    push(&head, 9);
    push(&head, 9);
    append(&head, 11);
    append(&head, 13);
    push(&head, 8);

    display(&head);

    return 0;
}