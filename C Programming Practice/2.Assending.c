#include<stdio.h>
int main()
{
    int len;
    printf("Enter the length of the array\n");
    scanf("%d",&len);
    int a[len];
    printf("Enter the Elements of the array\n");
    for(int i=0; i<len; i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0; i<len; i++)
    {
        for(int j=i+1; j<len; j++)
        {
            if(a[i]>a[j])
            {
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("The array in ascending order is as follows:\n");
    for(int i=0; i<len; i++)
    {
        printf("%d ",a[i]);
    }
}
