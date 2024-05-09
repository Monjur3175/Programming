#include <stdio.h>
int main()
{
    float h, m;
    scanf("%f %f", &h, &m);

    float dif1 = (((h * 5) + (5 * m / 60)) - m) * 6;

    float dif2 = 360 - dif1;

    if (dif2 > dif1)
    {
        printf("%.7f", dif1);
    }
    else
    {
        printf("%.7f", dif2);
    }

    return 0;
}