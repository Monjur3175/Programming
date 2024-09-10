#include <stdio.h>

int main() {
    printf("Enter the size of the array\n");
    int n;
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Here is the reversed array\n");
    for(int i=n-1;i>=0;i--){
        printf("%d ",arr[i]);
    }
    return 0;
}
