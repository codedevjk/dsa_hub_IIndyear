#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct stack
{
    int size;
    int top;
    int* arr;
};
int is_empty(struct stack* s)
{
    if(s->top==-1)
        return 1;
    return 0;
}
int is_full(struct stack* s)
{
    if(s->top==s->size-1)
        return 1;
    return 0;
}
void push(struct stack* s,int x)
{
    if(is_full(s))
        printf("stack overflow\n");
    else
    {
        s->top++;
        s->arr[s->top]=x;
        printf("push done\n");
    }
}
int pop(struct stack* s)
{
    if(is_empty(s))
    {
        printf("stack underflow\n");
        return -1;
    }
    else
    {
        int x=s->top;
        s->top--;
        return x;
    }
}
int peek(struct stack* s,int x)
{
    int k=s->top-x+1;
    if(s->top-x+1<0)
    {
       printf("not a valid position");
       return -1;
    }
    else
        return s->arr[k];
}
int stackTop(struct stack* s)
{
    if(is_full)
       return -1;
    else
       return s->arr[s->top];
}
int stackBottom(struct stack* s)
{
    if(is_empty)
       return -1;
    else 
       return s->arr[0];
}
void print(struct stack* s)
{
    int t=s->size;
    for(int i=1;i<=t;i++)
    {
        int k=peek(s,i);
        printf("%d\n",k);
    }
}
int main()
{
    struct stack* s=(struct stack*)malloc(sizeof(struct stack));
    printf("enter size of stack\n");
    scanf("%d",&s->size);
    s->top=-1;
    s->arr=(int*)malloc(s->size * sizeof(int));

    for(int i=0;i<s->size;i++)
    {
        int x;
        printf("enter element\n");
        scanf("%d",&x);
        push(s,x);
    }
    print(s);
}
