#include <bits/stdc++.h>
using namespace std;

void increment(int &n, int n1)
{
    n++;  // passed by reference(main value)
    n1++; // passed by value(copy value)
}
void swap(int &a, int &b)
{ // if we pass by value it will return same so reference needed
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << a << " " << b << endl;
    swap(a, b);
    cout << a << " " << b << endl;
    cout << max(a, b) << endl;
    cout << min(a, b) << endl;

    return 0;
}