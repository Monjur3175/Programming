#include<stdio.h>
int main()
{
    int a[3][3],b[3][3],c[3][3];
    printf("Matrix a:\n");
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d",&a[i][j]);
            printf("%2d",a[i][j]);
            printf("\n");
        }
    }
    printf("Matrix b:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d",&b[i][j]);
            printf("%2d",b[i][j]);
            printf("\n");
        }
    }
    printf("Sum d:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            c[i][j]=a[i][j]+b[i][j];
            printf("%4d",c[i][j]);
        }
        printf("\n");
    }
    return 0;
}