#include <stdio.h>

int main() {
    for(int i=5;i>=0;i--)//row
    {
        for(int j=1;j<=i;j++)//column
        {
            printf("%d ",j);
        }
        printf("\n");
    }
    return 0;
}
