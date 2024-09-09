#include<stdio.h>
struct Student
{
    char name[50];
    int roll;
    float marks;
};

int main()
{
    struct Student students[5];
    for(int i=0; i<5; i++)
    {
        printf("Enter the information for %d no. student\n",i+1);
        printf("Enter the name:");
        scanf(" %[^\n]%*c",students[i].name);
        printf("Enter the roll:");
        scanf("%d",&students[i].roll);
        printf("Enter the marks:");
        scanf("%f",&students[i].marks);
        printf("\n");
    }
    printf("Display the information of the students\n");
    for(int i=0; i<5; i++)
    {

        printf("Name: %s\n",students[i].name);
        printf("Roll: %d\n",students[i].roll);
        printf("Marks: %.2f\n",students[i].marks);
        printf("\n");
    }
}
