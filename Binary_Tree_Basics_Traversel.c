#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d\t", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(struct node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d\t", root->data);
    }
}
void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d\t", root->data);
        inOrder(root->right);
    }
}

int main()
{
    struct node *root;
    root = (struct node *)malloc(sizeof(struct node));
    root->data = 7;
    struct node *n1 = (struct node *)malloc(sizeof(struct node));
    n1->data = 4;
    struct node *n2 = (struct node *)malloc(sizeof(struct node));
    n2->data = 3;
    struct node *n3 = (struct node *)malloc(sizeof(struct node));
    n3->data = 5;
    struct node *n4 = (struct node *)malloc(sizeof(struct node));
    n4->data = 8;
    root->left = n1;
    root->right = n2;
    n2->right = NULL;
    n2->left = NULL;
    n1->right = n4;
    n1->left = n3;
    n4->right = n4->left = NULL;
    n3->right = n3->left = NULL;
    printf("This is pre order : ");
    preOrder(root);
    printf("\n");
    printf("This is post order : ");
    postOrder(root);
    printf("\n");
    printf("This is in order : ");
    inOrder(root);
    printf("\n");
    return 0;
}