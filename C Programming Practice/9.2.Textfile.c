#include<stdio.h>
int main()
{
    FILE *file;
    char name[20];
    int roll;
    file = fopen("Monjur.txt","w");
    if(file==NULL)
    {
        printf("Error opening the file!\n");
        return 1;
    }
    printf("Enter your name: ");
    scanf("%s",name);
    printf("Enter your Roll: ");
    scanf("%d",&roll);
    fprintf(file,"Name: %s",name);
    fprintf(file,"Roll: %d\n",roll);
    fclose(file);
    printf("Data is successfully written in Monjur.txt\n");
    return 0;
}
