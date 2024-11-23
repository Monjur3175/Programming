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
        }
    }
    printf("The array a is:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    printf("Matrix b:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    printf("The array b is:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
    printf("Sum d:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            c[i][j]=a[i][j]+b[i][j];
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
    return 0;
}
