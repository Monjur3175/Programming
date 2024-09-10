#include<stdio.h>
int main()
{
    FILE *file;
    file=fopen("Text.txt","w");
    char name[50];
    int roll;
    if(file==NULL)
    {
        printf("Error");
        return 1;
    }
    printf("Enter your name:");
    scanf("%s",name);
    printf("Enter your roll:");
    scanf("%d",&roll);
    fprintf(file,"Name:%s\n",name);
    fprintf(file,"Roll:%d\n",roll);
    fclose(file);
    printf("The data is successfully saved in Text.txt");
    return 0;
}
