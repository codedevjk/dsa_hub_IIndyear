#include<stdio.h>
 
void insertion(int a[],int n)
{
    int i,j,temp;
    for( i=1;i<n;i++)
    {
        temp=a[i];
        j=i-1;
        while(j>=0 && a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
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

    insertion(arr,n);
    printf("Sorted array:");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
