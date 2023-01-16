#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct node
{
    int data;
    struct node *next;
};
struct node *Allocate(int x)
{
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    if (nn == NULL)
        return NULL;
    nn->data = x;
    nn->next = NULL;
    return nn;
};
void display(struct node *fr, struct node *re)
{
    struct node *t;
    if (fr == NULL)
    {
        printf("Queue is empty");
        return;
    }
    for (t = fr; t != re; t = t->next)
    {
        printf("%d -> ", t->data);
    }
    printf("%d ", t->data);
}
void enqueue(struct node **fr, struct node **re, int x)
{
    struct node *nn = Allocate(x);
    if (nn == NULL)
    {
        printf("\nOverflow");
        return;
    }
    if (*fr == NULL)
    {
        nn->next = nn;
        *fr = *re = nn;
    }
    else
    {
        nn->next = *fr;
        (*re)->next = nn;
        *re = nn;
    }
}
int dequeue(struct node **fr, struct node **re)
{
    int x;
    struct node *temp;
    if (*fr == NULL)
    {
        printf("\nUnderflow");
        return INT_MIN;
    }
    temp = *fr;
    if (*fr == *re)
        *fr = *re = NULL;
    else
    {
        *fr = (*fr)->next;
        (*re)->next = *fr;
    }
    x = temp->data;
    free(temp);
    return x;
}
int main()
{
    struct node *front = NULL, *rear = NULL;
    int x;
    enqueue(&front, &rear, 1);
    enqueue(&front, &rear, 2);
    enqueue(&front, &rear, 3);
    enqueue(&front, &rear, 4);
    enqueue(&front, &rear, 5);
    enqueue(&front, &rear, 6);
    enqueue(&front, &rear, 7);
    enqueue(&front, &rear, 8);
    display(front, rear);
    x = dequeue(&front, &rear);
    if (x != INT_MIN)
        printf("\n%d is deleted", x);
    x = dequeue(&front, &rear);
    if (x != INT_MIN)
        printf("\n%d is deleted", x);
    x = dequeue(&front, &rear);
    if (x != INT_MIN)
        printf("\n%d is deleted", x);
    x = dequeue(&front, &rear);
    if (x != INT_MIN)
        printf("\n%d is deleted", x);
    x = dequeue(&front, &rear);
    if (x != INT_MIN)
        printf("\n%d is deleted", x);
    x = dequeue(&front, &rear);
    if (x != INT_MIN)
        printf("\n%d is deleted", x);
    x = dequeue(&front, &rear);
    if (x != INT_MIN)
        printf("\n%d is deleted", x);
    x = dequeue(&front, &rear);
    if (x != INT_MIN)
        printf("\n%d is deleted", x);
    x = dequeue(&front, &rear);
    if (x != INT_MIN)
        printf("\n%d is deleted", x);
    return 0;
}