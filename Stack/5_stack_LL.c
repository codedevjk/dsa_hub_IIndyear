#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include <stdbool.h>
struct node
{
    int data;
    struct node* next;
};
int isEmpty(struct node* top)
{
    if(top==NULL)
        return 1;
    return 0;
}
int isFull()
{
    //it will be full when there is no sapce in memory to allocate to new node
    //it can also be full when given a condition of maximum no of nodes
    struct node* new=(struct node*)malloc(sizeof(struct node));
    if(new==NULL)
        return 1;
    return 0;
}
struct node* push(struct node* top,int x)
{
    if(isFull(top))
    {
       printf("stack overflow");
       return top;
    }
    else
    {
        struct node* new=(struct node*)malloc(sizeof(struct node));
        new->data=x;
        new->next=top;
        top=new;
        return top;
    }
}
//can make top as global variable to not use pointer of pointer
int pop(struct node** top)
{
    if(isEmpty(*top))
    {
        printf("stack underflow");
        return -1;
    }
    else
    {
        struct node* new=*top;
        int x=(*top)->data;
        (*top)=(*top)->next;
        free(new);
        return x;
    }
}
int peek(struct node* top,int pos)
{
    struct node* new=top;
    int n=0;
    while((n<pos-1 && new!=NULL))
    {
        new=new->next;
        n++;
    }
    if(new!=NULL)
        return new->data;
    else
        return -1;
}
int stackTop(struct node* top)
{
    if(top==NULL)
       return -1;
    else
       return top->data;
}
int stackBottom(struct node* top)
{
    if(top==NULL)
       return -1;
    else
    {
            
    }
}
int main()
{
    struct node* top=NULL;
}