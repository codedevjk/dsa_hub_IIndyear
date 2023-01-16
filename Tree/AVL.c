#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
};
int height(struct node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
int max(int a, int b)
{
    return (a > b)? a : b;
}
struct node* newNode(int key)
{
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->key = key;
    n->left = NULL;
    n->right = NULL;
    n->height = 1; // new node is initially added at leaf
    return(n);
}
struct node *rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    return x;
}
struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    return y;
}
int getBalance(struct node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
struct node* insert(struct node* node, int key)
{
    if (node == NULL)
        return(newNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Equal keys not allowed
        return node;

    node->height = 1 + max(height(node->left),height(node->right));

    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
struct node* minValueNode(struct node* n)
{
    struct node* current = n;
    while (current->left != NULL)
        current = current->left;
    return current;
}
void preOrder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}
int main() 
{
    int n;
    scanf("%d",&n);
    int i=1;
    int t;
    
    struct node* root=NULL;
    for(;i<=n;i++)
    {
        scanf("%d",&t);
        root=insert(root,t);
    }
    preOrder(root);

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}