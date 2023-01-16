#include<stdio.h>

void selectionSort(int a[],int n)
{
   int i,j,min,temp;
   for(i=0;i<n-1;i++)
   {
     min=i;
    for(j=i+1;j<n;j++)
    {
        if(a[j]<a[min])
        min=j;
    }
    if(min!=i)
    {
        temp=a[min];
        a[min]=a[i];
        a[i]=temp;
    }
   }
}
/* Using pointers 
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
 
        // Swap the found minimum element with the first element
           if(min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }
}
*/
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

    selectionSort(arr,n);
    printf("Sorted array:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

}