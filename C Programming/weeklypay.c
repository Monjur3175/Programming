#include<stdio.h>
typedef long long ll;
int main ()
{
  ll hours,net,tax;
  scanf("%lld",&hours);
  ll basic=12*hours;
  if (hours>40)
  {
    hours=hours*(hours*.5)-40;
  }
  net=basic+(hours*basic);
  if (net<=300)
  {
    tax=net*15/100;
  }
  if (net>300&&net<=450)
  {
    tax=tax+net*20/100;
  }
  if (net>450)
  {
    tax=tax+net*25/100;
  }
  net=basic+(hours*basic)+tax;
  printf("%lld",net);
  return 0;
}