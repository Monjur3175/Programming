#include <stdio.h>

int factorial(int number)
{
    if (number == 0 || number == 1)
    {
        return 1;
    }
    else
    {
        return number * factorial(number - 1);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", factorial(n));
    return 0;
}
