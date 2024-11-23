#include<stdio.h>
int main()
{
    printf("Enter the number of string:\n");
    int len,x=0;
    scanf("%d",&len);
    printf("Enter the string of length %d:\n",len);
    char s1[len+1];
    scanf("%s",s1);
    int length=strlen(s1);
    printf("The length of the string is %d\n",length);
    for(int i=0; i<len/2; i++)
    {
        if(s1[i]!=s1[len-i-1])
        {
            x=1;
            break;
        }
    }
    if(x==1)
    {
        printf("The string is not Palindrome\n");
    }
    else
    {
        printf("The string is Palindrome\n");
    }
}
