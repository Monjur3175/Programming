#include<stdio.h>
int main ()
{
  int a,b;
  float m,n;
  scanf("%d %d",&a,&b);
  printf("%d %d\n",a+b,a-b);
  scanf("%f %f",&m,&n);
  printf("%.1f %.1f",m+n,m-n);
  return 0;
}