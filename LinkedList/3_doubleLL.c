#include <stdio.h>
#include <stdlib.h>
struct node
 {
    int data;
    struct node* next;
    struct node* prev;
};
struct node* push(struct node* head, int data)
{
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    new->next = (head);
    new->prev = NULL;
 
    if ((head) != NULL)
        (head)->prev = new;
 
    (head) = new;
    return head;
}
void insertAfter(struct node* prev, int data)
{
    if (prev == NULL) {
        printf("the given previous node cannot be NULL");
        return;
    }
    struct node* new
        = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    new->next = prev->next;
    prev->next = new;
    new->prev = prev;

    if (new->next != NULL)
        new->next->prev = new;
}
void append(struct node* head, int data)
{
    struct node* new = (struct node*)malloc(sizeof(struct node));
    struct node* last = head; 
    new->data = data;
    new->next = NULL;
 
    if (head == NULL) 
    {
        new->prev = NULL;
        head = new;
        return;
    }
 
    while (last->next != NULL)
        last = last->next;

    last->next = new;
    new->prev = last;
    return;
}
struct node* deleteNode(struct node* head, struct node* del)
{
    if (head == NULL || del == NULL)
        return head;
    if (head == del)
        head = del->next;

    if (del->next != NULL)
        del->next->prev = del->prev;

    if (del->prev != NULL)
        del->prev->next = del->next;

    free(del);
    return head;
}
void deleteNodeAtGivenPos(struct node* head, int n)
{
    if (head == NULL || n <= 0)
        return;
 
    struct node* current = head;
    int i;
    for (int i = 1; current != NULL && i < n; i++)
        current = current->next;
 
    if (current == NULL)
        return;

    deleteNode(head, current);
}
void printList(struct node* node)
{
    struct node* last;
    printf("\nTraversal in forward direction \n");
    while (node != NULL) {
        printf(" %d \n", node->data);
        last = node;
        node = node->next;
    }
 
    printf("\nTraversal in reverse direction \n");
    while (last != NULL) {
        printf(" %d\n", last->data);
        last = last->prev;
    }
}
void reverse(struct node* head)
{
    struct node* temp = NULL;
    struct node* current = head;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)
        head = temp->prev;
}
int main()
{
    struct node* head = NULL;

    append(head, 6);
    head=push(head, 7);
    head=push(head, 5);

    head=push(head, 1);
    append(head, 4);
    insertAfter(head->next, 8);
 
    printf("Created DLL is: ");
    printList(head);

    head=deleteNode(head, head); /*delete first node*/
    head=deleteNode(head, head->next); /*delete middle node*/
    head=deleteNode(head, head->next); /*delete last node*/
 
    /* Modified linked list will be NULL<-8->NULL */
    printf("\n Modified Linked list ");
    printList(head);
 
    deleteNodeAtGivenPos(head, 2);
    printf("\n Modified Linked list ");
    printList(head);
    getchar();
    return 0;
}
//done