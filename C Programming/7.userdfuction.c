#include <stdio.h>
// int product(int a,int b,int c);
// int main()
// {
//     int a,b,c;
//     scanf("%d %d",&a,&b);
//     printf("%d",product(a,b,c));
//     return 0;
// }
// int product(int a,int b,int c)
// {
//     c=a*b;
//     return c;
// }
int array_func(int arr[], int x);
int main()
{
    int x;
    scanf("%d",&x);
    int arr[10];
    for (int i = 0; i < x; i++)
    {
        scanf("%d", &arr[i]);
    }
    array_func(arr, x);
}
int array_func(int arr[], int x)
{
    for (int i = 0; i < x; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}