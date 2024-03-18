#include <stdio.h>

#define BASIC_PAY_RATE 12
#define OVERTIME_THRESHOLD 40
#define OVERTIME_RATE 1.5
#define TAX_RATE_1 0.15
#define TAX_RATE_2 0.20
#define TAX_RATE_3 0.25
#define TAX_THRESHOLD_1 300
#define TAX_THRESHOLD_2 450

int main()
{
    int hours_worked;
    double gross_pay, taxes, net_pay;

    // Input
    printf("Enter the number of hours worked in a week: ");
    scanf("%d", &hours_worked);

    // Calculate gross pay
    if (hours_worked <= OVERTIME_THRESHOLD)
    {
        gross_pay = hours_worked * BASIC_PAY_RATE;
    }
    else
    {
        gross_pay = (OVERTIME_THRESHOLD * BASIC_PAY_RATE) + ((hours_worked - OVERTIME_THRESHOLD) * BASIC_PAY_RATE * OVERTIME_RATE);
    }

    // Calculate taxes
    if (gross_pay <= TAX_THRESHOLD_1)
    {
        taxes = gross_pay * TAX_RATE_1;
    }
    else if (gross_pay <= TAX_THRESHOLD_2)
    {
        taxes = TAX_THRESHOLD_1 * TAX_RATE_1 + (gross_pay - TAX_THRESHOLD_1) * TAX_RATE_2;
    }
    else
    {
        taxes = TAX_THRESHOLD_1 * TAX_RATE_1 + (TAX_THRESHOLD_2 - TAX_THRESHOLD_1) * TAX_RATE_2 + (gross_pay - TAX_THRESHOLD_2) * TAX_RATE_3;
    }

    // Calculate net pay
    net_pay = gross_pay - taxes;

    // Output
    printf("Gross Pay: $%.2f\n", gross_pay);
    printf("Taxes: $%.2f\n", taxes);
    printf("Net Pay: $%.2f\n", net_pay);

    return 0;
}
