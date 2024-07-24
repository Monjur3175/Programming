#include<stdio.h>
int b=34;
int func(int b)
{
    static int myvar=98;
    printf("%d\n",myvar);
    myvar++;
    return b+myvar;

}

int main()
{
    int b=344;
    int val=func(b);
    printf("%d\n",val);
    val=func(b);
    printf("%d\n",val);
}
