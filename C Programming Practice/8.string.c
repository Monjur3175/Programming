#include <stdio.h>
#include<string.h>
int main() {
    int len,x;
    printf("Enter the length of the String\n");
    scanf("%d",&len);
    char s1[len];
    printf("Enter the String\n");
    scanf("%s",s1);
    for(int i=0;i<len/2;i++){
        if(s1[i]!=s1[len-i-1])
        {
            x=1;
            break;
        }
    }
    if(x!=1)
    {
        printf("Is Palindrome");
    }
    else{
        printf("Not Palindrome");
    }
    return 0;
}
