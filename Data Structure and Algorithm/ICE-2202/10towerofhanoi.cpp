#include <bits/stdc++.h>
using namespace std;

void hanoi(int n, char src, char helper, char dest)
{
    if (n == 0)
        return;
    hanoi(n - 1, src, dest, helper);
    cout << "Move disk " << n << " src " << src << " dest " << dest << '\n';
    hanoi(n - 1, helper, src, dest);
}

int main()
{
    int N;
    cin >> N;
    hanoi(N, 'A', 'B', 'C');
}
