#include<stdio.h>
#include<math.h>
#include<time.h>

int arr[100];

void merge_sort(int arr[],int low,int high);
void merge(int arr[],int low,int mid,int high);
void input(int arr[],int n);
void output(int arr[],int n);

int main(){
    clock_t starttime = clock();
    int n;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    input(arr,n);
    merge_sort(arr,0,n-1);
    output(arr,n);
    clock_t endtime = clock();
    printf("Time taken : %f",(endtime-starttime)/CLOCKS_PER_SEC);
    printf("\n");
    return 0;
}

void merge_sort(int arr[],int low,int high){
    int mid;
    if(low<high){
        mid = (low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

void merge(int arr[],int low,int mid,int high){
    int i,j,k,temp[100];
    i = low;
    k = low;
    j = mid+1;
    while(i<=mid && j<=high){
        if(arr[i]<=arr[j]){
            temp[k] = arr[i];
            k++;
            i++;
        }
        else{
            temp[k] = arr[j];
            k++;
            j++;
        }
    }
    while(i<=mid){
        temp[k] = arr[i];
        k++;
        i++;
    }
    while(j<=high){
        temp[k] = arr[j];
        k++;
        j++;
    }
    for(i=low;i<k;i++){
        arr[i] = temp[i];
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