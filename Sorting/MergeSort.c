#include<stdio.h>
#define MAXSIZE 100
void merge(int arr[], int low, int mid, int high)
{
        int temp[MAXSIZE];
        int i,j,k,z;
        i=low;
        j=mid+1;
        k=low;
        while(i<=mid && j<=high)
        {
            if(arr[i]<=arr[j])
            {
                temp[k]=arr[i];
                i++;
            }
            else
            {
                temp[k]=arr[j];
                j++;
            }
            k++;
        }
        while(j<=high)
        {
            temp[k]=arr[j];
            j++;
            k++;
        }
        while(i<=mid)
        {
            temp[k]=arr[i];
            i++;
            k++;
        }
         for(z=low;z<=high;z++)
            arr[z]=temp[z];
        
}
void mergeSort(int arr[], int l, int r)
{
    
    int mid;
    if(l<r)
    {
        mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}
int main()
{
    int arr[100];
    int l,h,n;

    printf("Enter the number of elements:");
    scanf("%d",&n);
    l=0;
    h=n-1;
    printf("Enter the elements :\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    mergeSort(arr,l,h);
    printf("Sorted array:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}