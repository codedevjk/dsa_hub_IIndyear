#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
//circular increment i=(i+1)%size and r,f intially 0
struct Cque
{
    int size;
    int f,r;
    int* arr;
};
int isFull(struct Cque* q)
{
    if((q->r+1)%q->size==q->f)
    {
        printf("\nque is full");
        return 1; 
    }
    return 0;
}
int isEmpty(struct Cque* q)
{
    if(q->r==-1 && q->f==-1)
    {
        printf("\nque is empty");
        return 1;
    }
    return 0;
}
void enque(struct Cque *q,int x)
{
    if(isFull(q))
       printf("\nque overflow");
    else if(q->f==-1 && q->r==-1)
    {
        q->f=q->r=0;
        q->arr[q->r]=x;
    }
    else 
    {   
        q->r=((q->r)+1)%q->size;
        q->arr[q->r]=x;
    }
}
int deque(struct Cque* q)
{
    int a=-1;
    if(isEmpty(q))
       printf("\nque underflow");
    a=q->arr[q->f];
    if(q->f==q->r)
    {
        q->f=q->r=-1;
    }
    else  
    {
        q->f=(q->f+1)%q->size;  
    }
    return a;
}
void printc(struct Cque* q)
{
    if (q->f == -1)
    {
        printf("\nQueue is Empty");
        return;
    }
    printf("\nElements in Circular Queue are: ");
    if (q->r >= q->f)
    {
        for (int i = q->f; i <= q->r; i++)
            printf("%d ",q->arr[i]);
    }
    else
    {
        for (int i = q->f; i <q->size; i++)
            printf("%d ", q->arr[i]);
 
        for (int i = 0; i <= q->r; i++)
            printf("%d ", q->arr[i]);
    }
}
/*void display(struct Cque* q)
{
    if(isEmpty(q))
        printf("\nQueue is Empty");
    else
    {
        int i=q->f;
        printf("\nque is:");
        while(i!=q->r)
        {
            printf("\n%d",q->arr[i]);
            i=(i+1)%q->size;
        }
    }
}*/
int main()
{
    struct Cque* q=(struct Cque*)malloc(sizeof(struct Cque));;
    q->size=4;
    q->f=q->r=-1;
    q->arr=(int*)malloc(q->size*sizeof(int));
    enque(q,1);
    enque(q,2);
    enque(q,3);
    enque(q,4);
    printc(q);
    int x;
    x=deque(q);
    printc(q);
    enque(q,5);
    enque(q,6);
    printc(q);
    return 0;
}