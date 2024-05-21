#include <bits/stdc++.h>
using namespace std;
void func(int n)
{
    if (n == 0)
    {
        return;
    }
    func(n - 1);//recursive call
    cout << n << endl;
}
int main()
{

    func(5);//function call
    return 0;
} // every recursive function must have a condition to stop