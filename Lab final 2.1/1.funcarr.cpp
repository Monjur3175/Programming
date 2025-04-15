#include <bits/stdc++.h>
using namespace std;
    int* createarr(int size)
    {
        int* arr=new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i]=i+1;
        }
        return arr;
    }

int main()
{
    int size;
    cin>>size;
    int* arr=createarr(size);
    cout<<"Array Elements"<<endl;
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    delete[] arr;
    return 0;
}
