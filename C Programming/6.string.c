#include <stdio.h>
#include <string.h>
int main()
{
    // char city[9]={"Rajshahi"} ;
    // char bus[10];
    // gets(bus);
    // printf("%s\n",city);
    // printf("%5c\n",city[2]);
    // puts(bus);
    // putchar(bus[0]);

    // char first_name[10] = "Monjur";
    // char second_name[10] = "Morshed";
    // char third_name[10] = "Osama";
    // char name[30]; // Large enough to hold the concatenated result with spaces

    // int i = 0; // Index for the 'name' array

    // // Copy first name
    // for (int j = 0; first_name[j] != '\0'; j++, i++)
    // {
    //     name[i] = first_name[j];
    // }
    // name[i++] = ' '; // Add space after the first name

    // // Copy second name
    // for (int j = 0; second_name[j] != '\0'; j++, i++)
    // {
    //     name[i] = second_name[j];
    // }
    // name[i++] = ' '; // Add space after the second name

    // // Copy third name
    // for (int j = 0; third_name[j] != '\0'; j++, i++)
    // {
    //     name[i] = third_name[j];
    // }

    // name[i] = '\0'; // Null-terminate the final string

    // printf("%s\n", name);

    // char lab[10];
    // char facility[10];
    // scanf("%s", lab);
    // scanf("%s", facility);

    // if (strcmp(lab, facility))
    // {
    //     printf("%s\n", strcat(lab, facility));
    // }
    // strcpy(lab,facility);
    // printf("%s\n",lab);
    // printf("%d",strlen(lab));

    // char udemy[10];
    // char course[10];
    // scanf("%s", udemy);
    // scanf("%s", course);
    // printf("%s",strncat(udemy,course,5));

    char x[10];
    char y[10];
    scanf("%s",x);
    scanf("%s",y);
    if (strstr(x,y))
    {
        printf("Yes\n");
    }
    
    
    return 0;
}