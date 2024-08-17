#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    if (a > b)
    {
        printf("%d\n", a);
    }
    else
    {
        printf("%d\n", b);
    }
    int flag = (a > b) ? a : b;
    printf("%d\n", flag);
    return 0;
}