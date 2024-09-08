#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];         //arr[5]
    for (int i = 0; i < n; i++) //0 1 2 3 4
    {
        scanf("%d", &arr[i]);   //arr[0],arr[1],arr[2],arr[3],arr[4]
    }
    for (int i = 0; i < n; i++)3
    {
        for (int j = i + 1; j < n; j++)4
        {
            if (arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

//      i j
//7 5 4 2 1

temp=1->i
i=2->j
j=1->temp
