#include<stdio.h>
int main()
{
     int a[6];
     for(int i=1;i<=6;i++){
        scanf("%d\n",&a[i]);}
        for(int i=1;i<=6;i++){
        printf("The elements of the array a[%d]=%d\n",i,a[i]);}

     int sum=0;
     for( int i=1;i<=6;i++)
        sum= sum+a[i];
     printf("Sum of the Array Elements=%d\n",sum);
       float avg= sum/6;
       printf(" Avrage of the element=%.3f\n",avg);
     return 0;
}
