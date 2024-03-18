#include <iostream>

using namespace std;
typedef long long ll;
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}

int main()
{
    int X;
    cin >> X;

    for (ll i = 1; i <= X; i++)
    {
        if (isPrime(i))
            cout << i << " ";
    }

    return 0;
}
