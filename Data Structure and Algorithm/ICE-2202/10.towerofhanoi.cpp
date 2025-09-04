#include <bits/stdc++.h>
using namespace std;

void hanoi(int n, char from, char aux, char to)
{
    if (n == 0)
        return;
    hanoi(n - 1, from, to, aux);
    cout << "Move disk " << n << " from " << from << " to " << to << '\n';
    hanoi(n - 1, aux, from, to);
}

int main()
{
    int N = 3;
    hanoi(N, 'A', 'B', 'C');
}
