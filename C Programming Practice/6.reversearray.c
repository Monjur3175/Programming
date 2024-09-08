#include <stdio.h>

int main() {
    printf("Enter the size of the array\n");
    int n;
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array\n");
    for(int i=0;i<n;i++){ //0 1 2 3 4
        scanf("%d",&arr[i]);
    }
    printf("Here is the reversed array\n");
    for(int i=n-1;i>=0;i--){ // 4 3 2 1 0
        printf("%d ",arr[i]);
    }
    return 0;
}
