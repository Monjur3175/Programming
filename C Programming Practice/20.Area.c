#include <stdio.h>
int main() {
    float height, width, depth, volume;
    printf("Enter the height of the cube: ");
    scanf("%f", &height);
    printf("Enter the width of the cube: ");
    scanf("%f", &width);
    printf("Enter the depth of the cube: ");
    scanf("%f", &depth);
    volume = height * width * depth;
    printf("The volume of the cube is: %.2f\n", volume);
    return 0;
}

