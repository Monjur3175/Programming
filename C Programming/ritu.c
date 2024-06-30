#include<stdio.h>

int main()
{
    int a[5],i,sum=0;
    printf("Enter 5 elements \n");
    for(i=0;i<5;i++){
    scanf("%d",&a[i]);
    }
    for(i=0;i<5;i++){
        sum=sum+a[i];
    }
    printf("Print Sum=%d\n",sum);
    float average=(float)sum/5;
    printf("Average=%f",average);
    return 0;
}
