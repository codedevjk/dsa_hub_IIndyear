#include<stdio.h>
 int count=0;
void bubble(int a[],int n)
{
    int i,j,temp,swap;

    for(i=0;i<n-1;i++)
    {
        swap=0;
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                swap=1;
                count++;
            }
        }
       if(swap==0)
        break;
    }
}

int main()
{
    int arr[100];
    int n;

    printf("Enter the number of elements:");
    scanf("%d",&n);

    printf("Enter the elements :\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    bubble(arr,n);
    printf("Sorted array:");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\nNo of swaps performed= %d",count);
}