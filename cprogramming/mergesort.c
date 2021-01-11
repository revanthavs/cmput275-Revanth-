#include <stdio.h>

int printarray(int *arr)
{
    int arrlength = sizeof(*arr)/sizeof(*(arr+1));
    for (int i = 0; i < arrlength; i++){
        printf("%d",*(arr+i));
    }
    printf("\n");
    return -1;
}

int main(){
    printf("Enter how the length of Array: \n");
    int arrsize;
    scanf("%d",&arrsize);
    int arr[arrsize];
    for (int i = 0; i < arrsize ; i++){
        scanf("%d",&arr[i]);
    }
    for (int i = 0; i < arrsize ; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    printarray(arr);
}
