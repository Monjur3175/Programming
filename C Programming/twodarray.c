#include <stdio.h>

int main()
{
    int x,a[4][4];
   printf("Enter 2D array elements\n");

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            scanf("%d\n",&a[i][j]);
        }    
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("The array elements are a[%d][%d] = %d\n",i,j,a[i][j]);
        }
        
        
    }
    
    
    return 0;
}
