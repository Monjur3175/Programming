#include<stdio.h>
int main()
{
    int a,b,sum=0;
    printf("Enter The number a and b\n");
    scanf("%d %d",&a,&b);
    printf("Enter the elements of the 2D array\n");
    int arr[a][b];
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            scanf("%d",&arr[i][j]);            
        }
    }
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            sum+=arr[i][j];
            printf("%d ",arr[i][j]);  
        }
        printf("\n");
    }
    printf("The sum of the elements of the array = %d",sum);
    return 0;
    
}