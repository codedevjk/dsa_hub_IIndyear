#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
struct que
{
    int size;
    int f,r;
    int* arr;
};
int isFull(struct que* q)
{
    if(q->r==q->size-1)
        return 1;
    return 0;
}
int isEmpty(struct que* q)
{
    if(q->r==q->f)
        return 1;
    return 0;
}
void enque(struct que *q,int x)
{
    if(isFull(q))
       printf("que is full");
    else    
        q->arr[++q->r]=x;
}
int deque(struct que* q)
{
    int a=-1;
    if(isEmpty(q))
       printf("que is empty");
    else  
    {
        q->f++;  
        a=q->arr[q->f];
    }
    return a;
}
void printc(struct que* q)
{
    if (q->f == -1)
    {
        printf("\nQueue is Empty");
        return;
    }
    printf("\nElements in Circular Queue are: ");
    for (int i = q->f; i <= q->r; i++)
        printf("%d ",q->arr[i]);
}
void reverseQueue(struct que* q)
{
    if (isEmpty(q))
        return;
    int fr = q->arr[q->f];
    int x=deque(q);
    reverseQueue(q);
    enque(q,fr);
}
int main()
{
    struct que* q=(struct que*)malloc(sizeof(struct que));
    q->size=100;
    q->f=q->r=-1;
    q->arr=(int*)malloc(q->size*sizeof(int));

}