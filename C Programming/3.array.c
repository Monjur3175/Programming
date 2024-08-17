#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("The elements of the array a[%d] = %d\n", i, a[i]);
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + a[i]; // sum+=a[i];
    }
    printf("Sum of the Array Elements=%d\n", sum);
    float avg = sum / (float)n;
    printf("Avrage of the element=%.3f\n", avg);
    return 0;
}