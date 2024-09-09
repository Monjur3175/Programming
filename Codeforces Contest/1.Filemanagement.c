#include <stdio.h>

int main()
{
    FILE *file;
    char name[50];
    int roll;
    file = fopen("Omor.txt", "w");
    if (file == NULL)
    {
        printf("The File has an Error");
    }
    else
    {
        printf("The File has been opened\n");
    }
    printf("Enter the name of the Student:");
    scanf("%s",name);
    printf("Enter the roll of the Student:");
    scanf("%d", &roll);
    fprintf(file, "The name of the Student is: %s\n", name);
    fprintf(file, "The Roll of the Student is: %d\n", roll);
    fclose(file);
    printf("The data is successfully Written in Omor.txt");

    return 0;
}