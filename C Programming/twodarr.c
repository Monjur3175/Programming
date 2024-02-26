#include<stdio.h>
int main()
{
    int a,b;
    scanf("%d %d\n",&a,&b);
    int arr[a][b];
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            scanf("%d\n",&arr[i][j]);
            
        }
    }
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            printf("%d ",arr[i][j]);  
        }
        printf("\n");
    }
    return 0;
    
}