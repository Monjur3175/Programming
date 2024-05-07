#include <stdio.h>

int main()
{
    int x,a[10];
   printf("Enter array elements\n");

    for (int i = 0; i < 10; i++)
    {
        scanf("%d\n",&a[i]);
    }
    for (int i = 0; i < 10; i++)
    {
        printf("The array elements are a[%d]=%d\n",i,a[i]);
    }
    
    
    return 0;
}
