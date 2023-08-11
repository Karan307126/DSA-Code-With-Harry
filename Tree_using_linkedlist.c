#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *right;
    struct node *left;
};

struct node *create()
{
    int val;
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    char cheak[4];
    printf("Do you want to add a new node? (yes or no) : ");
    scanf("%s", cheak);
    if (strcmp(cheak, "no") == 0)
    {
        return NULL;
    }
    printf("Enter data : ");
    scanf("%d", &val);
    new_node->data = val;
    printf("Enter left child %d.\n", val);
    new_node->left = create();
    printf("Enter right child %d.\n", val);
    new_node->right = create();
    return new_node;
}

void preorder(struct node *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void inorder(struct node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main()
{
    struct node *root = NULL;
    root = create();
    printf("\nThe inorderd traversel of tree is : ");
    inorder(root);
    printf("\nThe postorderd traversel of tree is : ");
    postorder(root);
    printf("\nThe preorderd traversel of tree is : ");
    preorder(root);
    return 0;
}