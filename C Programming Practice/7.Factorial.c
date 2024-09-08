#include <stdio.h>

int factorial(int a)
{
    if(a==0||a==1)
    {
        return 1;
    }
    else
    {
        return a*factorial(a-1);
    }
}
int main() {
    int n;
    scanf("%d",&n);
    factorial(n);
    return 0;
}
//5!=5*4*3*2*1
//9!=9*8*7*6*5*4*3*2*1
//0!=1
//1!=1


//5!=5*4!
//4!=4*3*2*1
