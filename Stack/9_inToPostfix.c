#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
struct stack
{
    int size;
    int top;
    char* arr;
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
        //printf("push done\n");
    }
}
char pop(struct stack* s)
{
   /*if(is_empty(s))
    {
        printf("stack underflow\n");
        return -1;
    }*/
    //else
   // {
        char x=s->top;
        s->top--;
        return x;
    //}
}
char stackTop(struct stack* s)
{
    if(is_full)
       return -1;
    else
       return s->arr[s->top];
}
char stackBottom(struct stack* s)
{
    if(is_empty)
       return -1;
    else 
       return s->arr[0];
}

int precedence(char x)
{
    if(x=='^')
        return 3;
    else if(x=='*'||x=='/'||x=='%')
        return 2;
    else if(x=='*'||x=='-')
        return 1;
    else
        return 0;
        
}
char associvity(char x)
{
    if(x=='='||x=='^')
       return 'R';
    return 'L';
}
int isOperator(char ch)
{
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='%'||ch=='^'||ch=='=')
       return 1;
    return 0;
}
char* infix_postfix(char infix[])
{
    struct stack* sp =(struct stack*)malloc(sizeof(struct stack));
    sp->size=100;
    sp->top=-1;
    sp->arr=(char*)malloc(sp->size*sizeof(char));
    int i=0,j=0;
    char* postfix=(char*)malloc((strlen(infix)+1)*sizeof(char));
    while(infix[i]!='\0')
    {
        char ch=infix[i];
        if(ch=='(')
            push(sp,'(');
        else if(ch==')')
        {
            char x=pop(sp);
            while(x!='(')
            {
                postfix[j++]=x;
                x=pop(sp);
            }
        }
        else if(!isOperator(ch))
        {
            postfix[j++]=ch;
        }
        else
        {
            while(precedence(stackTop(sp))>precedence(ch))
                  postfix[j++]=pop(sp);
            while(precedence(stackTop(sp))==precedence(ch)&&associvity(ch)=='L')
                postfix[j++]=pop(sp);
            push(sp,ch);
        }
        i++;
    }
    postfix[j]='\0';
}

int main()
{
    char in[] = "x-y/z-k*d";
    printf("\n postfix is %s\n",infix_postfix(in));
    getch();
    return 0;
}
