#include <stdio.h>

int saikat(int x)
{
    return x;//called
}
int monjur(int y)
{
    return y;
}
int main(){
    int x,y;
    scanf("%d %d",&x,&y);
    saikat(x);//calling
    monjur(y);
    return 0;
}

