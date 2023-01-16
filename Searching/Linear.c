#include<stdio.h>

int linear(int a[],int n,int item)
{
    int pos=-1;
    for(int i=0;i<n;i++)
    {
        if(a[i]==item)
        {
            pos=i+1;
            break;
        }

    }
    return pos;
}
int main()
{
    int arr[100];
    int n,item;

    printf("Enter the number of elements:");
    scanf("%d",&n);

    printf("Enter the elements :\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the item to search:");
    scanf("%d",&item);

    int a=linear(arr,n,item);
    if(a==-1)
     printf("Invalid item");
     else
      printf("Item is at position %d",a);
}
