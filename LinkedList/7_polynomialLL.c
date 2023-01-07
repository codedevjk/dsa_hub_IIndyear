#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct node
{
    int coeff;
    int exp;
    struct node* next;
};
struct node* allocate(int c,int e)
{
    struct node* new=(struct node* )malloc(sizeof(struct node));
    new->coeff=c;
    new->exp=e;
    new->next=NULL;
    return new;  
}
struct node* create(struct node* head)
{
    int c,e;
    printf("enter the coefficient and exponent");
    scanf("%d %d",&c,&e);
    struct node* curr,*save,*new;
    
    do
    {
        struct node* new=allocate(c,e);
        if(head==NULL|| e > head->exp)
        {
            new->next=head;
            head=new;
        }
        else
        {
            curr=head;
            while(curr && e < curr->exp)
            {
                save=curr;
                curr=curr->next;
            }
            if(curr==NULL|| e!=curr->exp)
            {
                save->next=new;
                new->next=curr;
            }
            else
            {
                curr->coeff= curr->coeff + c;
                free(new); 
            }
        }
        printf("enter the coefficient and exponent");
        scanf("%d %d",&c,&e);
    } while (e>=0);
    return head;
}
struct node* insert(struct node* head3,int c,int e)
{
    struct node* new=allocate(c,e);
    struct node* curr;
    if(head3==NULL)
    {
        head3=new;
    }
    else
    {
        curr=head3;
        while(curr!=NULL)
        {
            curr=curr->next;
        }
        curr->next=new;
    }
    return head3;
}
struct node* mul(struct node* head1,struct node* head2,struct node* head4)
{
    struct node* t1,*t2;
    t2=head2;
    while(t2!=NULL)
    {
        t1=head1;
        while(t1!=NULL)
        {
            head4=insert(head4,(t1->coeff*t2->coeff),(t1->exp+t2->exp));
            t1=t1->next;
        }
        t2=t2->next;
    }
    return head4;
}
struct node* add(struct node* head1,struct node* head2,struct node* head3)
{
    struct node* t1,*t2,*new;
    t1=head1;
    t2=head2;
    while(t1!=NULL && t2!=NULL)
    {
        if(t1->exp>t2->exp)
        {
            head3=insert(head3,t1->coeff,t1->exp);
            t1=t1->next;
        }
        else if(t1->exp<t2->exp)
        {
            head3=insert(head3,t2->coeff,t2->exp);
            t2=t2->next;
        }
        else
        {
            head3=insert(head3,t1->coeff+t2->coeff,t1->exp);
            t1=t1->next;
            t2=t2->next;
        }
    }
    while(t1!=NULL)
    {
        head3=insert(head3,t1->coeff,t1->exp);
        t1=t1->next;
    }
    while(t2!=NULL)
    {
        head3=insert(head3,t2->coeff,t2->exp);
        t2=t2->next;
    }
    return head3;
}
void print(struct node* head)
{
    struct node* curr=head;
    if(head==NULL)
    {
        printf("Empty list");
    }
    else
    {
        for(curr=head;curr->next!=NULL;curr=curr->next)
        {
            printf("%dx^%d+",curr->coeff,curr->exp);
        }
    
        if(curr->exp==0)
           printf("%d",curr->coeff);
        else
           printf("%dx^%d",curr->coeff,curr->exp);
    }
}
int main()
{
    struct node* head1=NULL,*head2=NULL,*head3=NULL,*head4=NULL;
    printf("\nenter the first polynomial\n");
    head1=create(head1);
    printf("\nenter the second polynomial\n");
    head2=create(head2);
    printf("\nFirst polynomial\n");
    print(head1);
    printf("\nSecond polynomial\n");
    print(head2);
    printf("\nSum of two polynomials\n");
    head3=add(head1,head2,head3);
    print(head3);
    printf("\nproduct of two polynomials\n");
    head4=mul(head1,head2,head4);
    print(head4);
    return 0;
}
//done