#include<stdio.h>
int product(int a,int b,int c)
{
    c=a*b;
    return c;
}
int main()
{
    int a,b,c;
    scanf("%d %d",&a,&b);
    printf("%d",product(a,b,c));
}
