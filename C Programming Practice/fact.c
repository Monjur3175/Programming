#include<stdio.h>

int factorial(int n)//called function
{
    if(n==0||n==1)
    {
        return 1;
    }
    else
    {
        return n*factorial(n-1);
    }
}

int main()
{
   int n;
   printf("Enter a number:");
   scanf("%d",&n);
   int fact=factorial(n);//calling function
   printf("The factorial of %d is %d\n",n,fact);
   return 0;
}
