#include<stdio.h>
#include<math.h>

int arr[100];

void insertion_sort(int arr[],int n);
void input(int arr[],int n);
void output(int arr[],int n);

int main()
{
    int n;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    input(arr,n);
    insertion_sort(arr,n);
    output(arr,n);
    return 0;
}

void insertion_sort(int arr[],int n){
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        temp = arr[i];
        j = i-1;
        while((j>=0) && (temp<arr[j]))
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

void input(int arr[],int n){
    int i;
    printf("Enter the elements : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
}

void output(int arr[],int n){
    int i;
    printf("The sorted array is : ");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}