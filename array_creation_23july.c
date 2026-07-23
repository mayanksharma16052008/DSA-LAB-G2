#include<stdio.h>
int main()
{
    int a[100],n;
    printf("enter nunber of elements in array");
    scanf("%d",&n);
    printf("enter array elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("elements of an array are");
    for(int i=0;i<n;i++){
        printf("%d",a[i]);
    }
    return 0;
}