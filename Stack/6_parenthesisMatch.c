#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
char stackTop(struct stack* s)
{
    if(is_full)
       return -1;
    else
       return s->arr[s->top];
}
int push(struct stack* s,char x)
{
    if(is_full(s))
    {
        return 0;
    }
    else
    {
        s->top++;
        s->arr[s->top]=x;
        return 1;
    }
}
char pop(struct stack* s)
{
    if(is_empty(s))
    {
        return -1;
    }
    else
    {
        char x=s->arr[s->top];
        s->top--;
        return x;
    }
}
int match(char a,char b)
{
    if(a=='('&& b==')')
        return 1;
    if(a=='{'&& b=='}')
        return 1;
    if(a=='['&& b==']')
        return 1;
    return 0;

}
int paranthesisMatch(char* exp)
{
    struct stack*sp=(struct stack*)malloc(sizeof(struct stack));
    sp->size=100;
    sp->top=-1;
    sp->arr=(char*)malloc(sp->size*sizeof(char));

    int i=0;
    for(int i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
        {
            push(sp,exp[i]);
        }
        else if(exp[i]==')'||exp[i]=='}'||exp[i]==']')
        {
            if(is_empty(sp))
            {
                return 0;
            }
            char t=pop(sp);
            if(!match(t,exp[i]))
            {
                return 0;
            }
        }
    }
    if(is_empty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void main()
{
    char n[150] ;
    fgets(n,150,stdin);
    if(paranthesisMatch(n))
    {
        printf("paranthesis is matching");
    }
    else{
        printf("paraenthesis not matching");
    }   
}