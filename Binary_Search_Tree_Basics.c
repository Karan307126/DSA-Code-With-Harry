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
        printf("%d  ", root->data);
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
        printf("%d  ", root->data);
    }
}
void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d  ", root->data);
        inOrder(root->right);
    }
}

int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
            return 0;
        if (prev != NULL && root->data <= prev->data)
            return 0;
        prev = root;
        return isBST(root->right);
    }
    else
        return 1;
}

struct node *searchRec(struct node *root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->data == key)
        return root;
    else if (root->data > key)
        return searchRec(root->left, key);
    else
        return searchRec(root->right, key);
}

struct node *searchItr(struct node *root, int key)
{
    while (root != NULL)
    {
        if (root->data == key)
            return root;
        else if (root->data > key)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

void insertion(struct node *root, int key)
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (root->data == key)
        {
            printf("Cann't able to insert %d because this key is alredy in this BST.", key);
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = key;
    new->right = NULL;
    new->left = NULL;
    if (prev->data > key)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
}

struct node *inOrderPrecesses(struct node *root)
{
    root = root->left;
    while(root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct node *deletion(struct node *root, int value)
{
    if (root == NULL)
        return NULL;
    else if (root->right == NULL && root->left == NULL)
    {
        free(root);
        return NULL;
    }
    if (root->data > value)
    {
        root->left = deletion(root->left, value);
    }
    else if(value > root->data)
    {
        root->right = deletion(root->right, value);
    }
    else{
        struct node *ipre = inOrderPrecesses(root);
        root->data = ipre->data;
        root->left = deletion(root->left, ipre->data);
    }
    return root;
}

int main()
{
    struct node *root;
    root = (struct node *)malloc(sizeof(struct node));
    root->data = 7;
    struct node *n1 = (struct node *)malloc(sizeof(struct node));
    n1->data = 4;
    struct node *n2 = (struct node *)malloc(sizeof(struct node));
    n2->data = 9;
    struct node *n3 = (struct node *)malloc(sizeof(struct node));
    n3->data = 2;
    struct node *n4 = (struct node *)malloc(sizeof(struct node));
    n4->data = 6;
    root->left = n1;
    root->right = n2;
    n2->right = NULL;
    n2->left = NULL;
    n1->right = n4;
    n1->left = n3;
    n4->right = n4->left = NULL;
    n3->right = n3->left = NULL;
    // printf("This is pre order :  ");
    // preOrder(root);
    // printf("\n");
    // printf("This is post order : ");
    // postOrder(root);
    // printf("\n");
    // printf("This is in order :   ");
    inOrder(root);
    printf("\n");
    // if (isBST(root))
    // {
    //     printf("This Binary tree is Binary search tree.\n");
    //     struct node *n = searchItr(root, 6);
    //     if (n != NULL)
    //         printf("Found : %d", n->data);
    //     else
    //         printf("Element is not found.");
    // }
    // else
    //     printf("This Binary tree isn't Binary search tree.");
    insertion(root, 3);
    inOrder(root);
    printf("\n");
    insertion(root, 1);
    inOrder(root);
    printf("\n");
    insertion(root, 5);
    inOrder(root);
    printf("\n");
    deletion(root, 5);
    inOrder(root);
    return 0;
}