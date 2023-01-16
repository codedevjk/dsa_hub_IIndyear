#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct node
{
    int data;
    int prn;
    struct node *next;
};
struct node *Allocate(int val, int p)
{
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    if (nn != NULL)
    {
        nn->data = val;
        nn->prn = p;
        nn->next = NULL;
    }
    return nn;
};
void display(struct node *head)
{
    struct node *cur;
    if (head == NULL)
    {
        printf("Queue is empty");
        return;
    }
    for (cur = head; cur->next != NULL; cur = cur->next)
    {
        printf("(%d,%d)-> ", cur->data, cur->prn);
    }
    printf("(%d,%d)", cur->data, cur->prn);
}
void enqueue(struct node **head, int val, int p)
{
    struct node *save, *cur;
    struct node *nn = Allocate(val, p);
    if (nn == NULL)
    {
        printf("Overflow\n");
        return;
    }
    if (*head == NULL || p < (*head)->prn)
    {
        nn->next = *head;
        *head = nn;
        return;
    }
    cur = *head;
    while (cur != NULL && p >= cur->prn)
    {
        save = cur;
        cur = cur->next;
    }
    save->next = nn;
    nn->next = cur;
}
int dequeue(struct node **head)
{
    struct node *temp;
    int x;
    if (*head == NULL)
    {
        printf("\nUnderflow\n");
        return INT_MIN;
    }
    temp = *head;
    *head = (*head)->next;
    x = temp->data;
    free(temp);
    return x;
}
int main()
{
    struct node *head = NULL;
    int x;
    enqueue(&head, 15, 4);
    enqueue(&head, 8, 2);
    enqueue(&head, 6, 7);
    enqueue(&head, 15, 1);
    enqueue(&head, 19, 5);
    enqueue(&head, 23, 2);
    display(head);
    x = dequeue(&head);
    if (x != INT_MIN)
        printf("\n%d is deleted", x);
    x = dequeue(&head);
    if (x != INT_MIN)
        printf("\n%d is deleted", x);
    x = dequeue(&head);
    if (x != INT_MIN)
        printf("\n%d is deleted", x);
    x = dequeue(&head);
    if (x != INT_MIN)
        printf("\n%d is deleted", x);
    x = dequeue(&head);
    if (x != INT_MIN)
        printf("\n%d is deleted", x);
    x = dequeue(&head);
    if (x != INT_MIN)
        printf("\n%d is deleted", x);
    x = dequeue(&head);
    if (x != INT_MIN)
        printf("\n%d is deleted", x);
    return 0;
}
