#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node
{
    int data;
    struct node* next;
};
void print(struct node* n)
{
    while(n!=NULL)
    {
        printf("%d \n",n->data);
        n=n->next;
    }
}
 //inserts a new node on the front of the list. 
struct node* push(struct node* head, int data)
{
    struct node* new = (struct node*) malloc(sizeof(struct node));
    new->data  = data;
    new->next = head;
  
    return new;
}
/* Given a node prev_node, insert a new node after the given
   prev_node */
void insertAfter(struct node* prev, int data)
{
    if (prev == NULL)
    {
      printf("the given previous node cannot be NULL");
      return;
    }
    struct node* new =(struct node*) malloc(sizeof(struct node));
    new->data  = data;
    new->next = prev->next;
    prev->next = new;
} 
// appends a new node at the end  
struct node* append(struct node* head, int data)
{
    struct node* new = (struct node*) malloc(sizeof(struct node));
    struct node *last = head;  

    new->data  = data;
    new->next = NULL;
 
    if (head == NULL)
    {
       head = new;
       return head;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new;
    return head;
}
struct node* insert_pos(struct node* head,int data,int pos)
{
    int c=1;
    struct node* new = (struct node*) malloc(sizeof(struct node));
    struct node* curr=head;
    struct node* prev=NULL;
    new->data=data;
    if(pos==1)
    {
         new->next=head;
         head=new;
        return head;
    }
    while(curr->next!=NULL)
    {
        c++;
        prev=curr;
        curr=curr->next;
        if(c==pos)
        {
            prev->next=new;
            new->next=curr;
            return head;
        }
    }
    return head;    
}
struct node* delete_start(struct node* head)
{
      struct node* new = head;
      head=head->next;
      free(new);
      return head;
}

void delete_end(struct node* head)
{
     struct node* new = (struct node*) malloc(sizeof(struct node));
     while((head->next)->next!=NULL)
     {
        head=head->next;
     }
     new=head->next;
     head->next=NULL;
     free(new);
}
//deletes the node at given position
struct node* delete_pos(struct node* head, int position)
{
    struct node* temp= (struct node*) malloc(sizeof(struct node));
    struct node* prev= (struct node*) malloc(sizeof(struct node));
    temp = head;
    prev = head;
    for (int i = 0; i < position; i++)
    {
        if (i == 0 && position == 1) 
        {
            head = (head)->next;
            free(temp);
        }
        else 
        {
            if (i == position - 1 && temp) 
            {
                prev->next = temp->next;
                free(temp);
            }
            else 
            {
                prev = temp;
                if (prev == NULL)
                    break;
                temp = temp->next;
            }
        }
    }
    return head;
}
//deletes the node of given value
struct node* delete_value(struct node* head, int key)
{
    struct node *temp = head, *prev;
    if (temp != NULL && temp->data == key) 
    {
        head = temp->next; 
        free(temp); 
        return head;
    }
 
    while (temp != NULL && temp->data != key) 
    {
        prev = temp;
        temp = temp->next;
    }
 
    if (temp == NULL)
        return head;
    prev->next = temp->next;
    free(temp); 
    return head;
}
struct node* reverse(struct node* head)
{
    struct node* prev = NULL;
    struct node* current =head;
    struct node* next = NULL;
    while (current != NULL) 
    {
        
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head= prev;
    return head;
}
//to check loop in the list
bool loop(struct node* head)
{
    struct node* new=(struct node*)malloc(sizeof(struct node*));
    while(head->next!=NULL)
    {
        if(head->next==new)
            return true;
        struct node* temp=head->next;
        head->next =new;
        head=temp;
    }
    return false;    
}
int main()
{
    struct node* first;
    struct node* second;
    struct node* third;
    first=(struct node *)malloc(sizeof(struct node));
    second=(struct node *)malloc(sizeof(struct node));
    third=(struct node *)malloc(sizeof(struct node));
    
    first->data=1;
    second->data=4;
    third->data=5;

    first->next=second;
    second->next=third;
    third->next=NULL;

    
    printf("original linked list:\n");
    print(first);

    first=push(first,0);
    insertAfter(first->next,2);
    first=append(first,6);
    first=insert_pos(first,3,4);

    printf("changed linked list:\n");
    print(first);

    first=delete_start(first);
    delete_end(first);
    first=delete_pos(first,3);
    first=delete_value(first,2);

    printf("changed linked list:\n");
    print(first);

    first=reverse(first);
    printf("changed linked list:\n");
    print(first);

    if(loop(first))
       printf("loop detected");
    else
       printf("no loop detected");
    return 0;
}
//done
