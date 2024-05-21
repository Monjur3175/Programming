#include <stdio.h>
int main()
{
    int a[10];
    printf("Enter the 10 elements:\n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("The elements of the array are:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d", a[i]);
    }
    for (int i = 0; i < 10; i++)
    {
        sum = sum + a[i];
         cnt = cnt + 1;
    }
    int avg = sum / cnt;
    printf("%d", sum);
    printf("%d", avg);
    return 0;
}