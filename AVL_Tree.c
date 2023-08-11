#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
};

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int getHeight(struct node *n)
{
    if (n == NULL)
        return 0;

    return n->height;
}

struct node *createNode(int key)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->key = key;
    new->left = NULL;
    new->right = NULL;
    new->height = 1;
    return new;
}

int getBalance(struct node *n)
{
    if (n == NULL)
        return 0;

    return (getHeight(n->left) - getHeight(n->right));
}

struct node *leftRotation(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;
    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

struct node *rightRotation(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;

    x->right = y;
    y->left = T2;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return x;
}

struct node *insert(struct node *root, int key)
{
    if (root == NULL)
        return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);

    else if (key > root->key)
        root->right = insert(root->right, key);

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int bf = getBalance(root);
    // left Left case
    if (bf > 1 && key < root->left->key)
        return rightRotation(root);

    // Right Right case
    if (bf < -1 && key > root->right->key)
        return leftRotation(root);

    // Left Right case
    if (bf > 1 && key > root->left->key)
    {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }

    // Right Left case
    if (bf < -1 && key < root->right->key)
    {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }
    return root;
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    struct node *root = NULL;

    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);
    preorder(root);
    return 0;
}