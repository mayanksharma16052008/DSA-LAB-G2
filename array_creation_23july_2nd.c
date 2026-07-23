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
    printf("\n");
    int pos,item;
    printf("Enter position: ");
    scanf("%d",&pos);
    printf("Enter element: ");
    scanf("%d",&item);

    for(int i=n;i>=pos;i--){
        a[i]=a[i-1];

    }
    a[pos-1]=item;
    n++;

    printf("After insertion elements are: ");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;

}