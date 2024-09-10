#include<stdio.h>

int osama(int a,int b)//called function
{
    return a-b;
}
float labib(int a,int b)//called function
{
    if(b!=0)
    {
        return (float)a/b;
    }
    else {
        printf("Not Divisable");
    }
}
int main()
{
    int a;
    int b;
    printf("Enter 2 number:");
    scanf("%d %d",&a,&b);
    int sum=osama(a,b);
    float product=labib(a,b);
    printf("The sum of %d and %d is %d\n",a,b,sum);
    printf("The product of %d and %d is %.2f\n",a,b,product);
    return 0;
}
