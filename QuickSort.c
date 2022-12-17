#include<stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
int partition(int a[],int l,int h)
{
    int pivot=a[l];
    int i=l,j=h;
    while(i<j)
    {
        do
        {
            i++;
        } while (a[i]<=pivot);
        do
        {
            j--;
        } while (a[j]>pivot);
        if(i<j)
        {
            swap(&a[i],&a[j]);
        }   
    }
    swap(&a[l],&a[j]);
    return j;

}

void quicksort(int a[],int l,int h)
{
    if(l<h)
    {
        int j=partition(a,l,h);
        quicksort(a,l,j);
        quicksort(a,j+1,h);
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

    quicksort(arr,0,n);
    printf("Sorted array:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

}
