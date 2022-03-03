/**
 * @file BinarySearchTree.c
 * @author Jahid A M (2147033)
 * @date 2022-03-03
 *
 */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
    }
    else if (data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

struct Node *search(struct Node *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->data == data)
    {
        return root;
    }
    else if (data <= root->data)
    {
        return search(root->left, data);
    }
    else
    {
        return search(root->right, data);
    }
}

struct Node *minValueNode(struct Node *root)
{
    struct Node *current = root;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

struct Node *deleteNode(struct Node *root, int data)
{
    // Base Case
    if (root == NULL)
        return root;

    // If the data to be deleted is smaller than the root's data,
    // then it lies in left subtree
    if (data < root->data)
        root->left = deleteNode(root->left, data);

    // If the data to be deleted is greater than the root's data,
    // then it lies in right subtree
    else if (data > root->data)
        root->right = deleteNode(root->right, data);

    // If data is same as root's data, then this is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct Node *temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main()
{

    /* Menu  */
    int choice;
    struct Node *root = NULL;
    int data;
    int search_data;
    int delete_data;
    int result;

    while (1)
    {
        printf("\n\n1. Insert\n2. Search\n3. Delete\n4. Inorder Traversal\n5. Exit\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        case 2:
            printf("Enter the data to be searched: ");
            scanf("%d", &search_data);
            result = search(root, search_data);
            if (result == NULL)
                printf("Element not found");
            else
                printf("Element found");
            break;
        case 3:
            printf("Enter the data to be deleted: ");
            scanf("%d", &delete_data);
            root = deleteNode(root, delete_data);
            break;
        case 4:
            printf("Inorder Traversal: ");
            inorder(root);
            break;
        case 5:
            exit(0);
        default:
            printf("Wrong choice\n");
        }
    }
}