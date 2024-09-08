#include <stdio.h>
int subtract(int a, int b) {
    return a - b;
}
float divide(int a, int b) {
    if (b != 0) {
        return (float)a / b;
    } else {
        printf("Error: Division by zero is not allowed.\n");
        return 0;
    }
}
int main() {
    int num1, num2;
    int difference;
    float quotient;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    difference = subtract(num1, num2);
    quotient = divide(num1, num2);
    printf("Difference: %d\n", difference);
    if (num2 != 0) {
        printf("Quotient: %.5f\n", quotient);
    }

    return 0;
}
