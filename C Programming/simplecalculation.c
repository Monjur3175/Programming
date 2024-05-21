#include<stdio.h>
int main ()
{
  int a,b,d,e;
  float c,f;
  scanf("%d %d %f\n",&a,&b,&c);
  scanf("%d %d %f",&d,&e,&f);
  float x=(b*c)+(e*f);
  printf("VALOR A PAGAR: R$ %.2f\n",x);
  return 0;
}