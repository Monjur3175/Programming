#include <stdio.h>
int main() {
    FILE *file;
    char name[50];
    int roll;
    file = fopen("Morshed.txt", "w");
    if (file == NULL) {
        printf("Error opening the file!\n");
        return 1;
    }
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    printf("Enter your roll number: ");
    scanf("%d", &roll);
    fprintf(file, "Name: %s", name);
    fprintf(file, "Roll: %d\n", roll);
    fclose(file);
    printf("Data successfully written to 'Morshed.txt'.\n");
    return 0;
}
