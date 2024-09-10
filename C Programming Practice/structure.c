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
    for(int i=0;i<5;i++)
    {
        printf("Enter the information of Student no.%d\n",i+1);
        printf("Enter the name:");
        scanf(" %[^\n]%*c",students[i].name);
        printf("Enter the roll:");
        scanf("%d",&students[i].roll);
        printf("Enter the marks:");
        scanf("%f",&students[i].marks);
    }

    for(int i=0;i<5;i++)
    {
        printf("Printing the information of Student no.%d\n",i+1);
        printf("Name:%s\n",students[i].name);
        printf("Roll:%d\n",students[i].roll);
        printf("Marks:%.2f\n\n",students[i].marks);
    }

    return 0;
}
