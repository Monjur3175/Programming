#include <stdio.h>

void add(int a, int b) {
    printf("Sum= %d\n",a+b);
}
int multiply(int a, int b) {//called
    return a * b;
}
int main(){
    int num1, num2, sum, product;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    add(num1, num2);
    product = multiply(num1, num2);//calling
    //printf("Sum: %d\n", sum);
    printf("Product: %d\n", product);
    return 0;
}
