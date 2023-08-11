#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int item)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = item;
    new_node->right = new_node->left = NULL;
    return new_node;
}

struct node *InorderSuccesor(struct node *root)
{
    struct node *temp = root;
    while (temp && temp->left != NULL)
        temp = temp->left;

    return temp;
}

struct node *createBST(struct node *root, int key)
{
    if (root == NULL)
        return newNode(key);

    else if (root->data < key)
        root->right = createBST(root->right, key);

    else if (root->data > key)
        root->left = createBST(root->left, key);

    return root;
}

struct node *deletion(struct node *root, int val)
{
    if (root == NULL)
        return NULL;

    if (val < root->data)
        root->left = deletion(root->left, val);
    else if (val > root->data)
        root->right = deletion(root->right, val);
    else
    {
        struct node *ptr;
        if (root->left == NULL)
        {
            ptr = root->right;
            free(root);
            return ptr;
        }
        else if (root->right == NULL)
        {
            ptr = root->left;
            free(root);
            return ptr;
        }
        struct node *temp = InorderSuccesor(root->right);
        root->data = temp->data;
        root->right = deletion(root->right, temp->data);
    }
    return root;
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

    root = createBST(root, 75);
    createBST(root, 38);
    createBST(root, 81);
    createBST(root, 46);
    createBST(root, 50);
    createBST(root, 19);
    createBST(root, 92);
    createBST(root, 27);
    createBST(root, 64);
    createBST(root, 03);

    printf("Inoderd traversel is : ");
    inorder(root);
    root = deletion(root, 75);
    printf("\nInoderd traversel is : ");
    inorder(root);
    return 0;
}