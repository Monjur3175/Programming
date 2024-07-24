#include <iostream>
using namespace std;
int x, y, k, t, m;
main()
{
    cin >> t;
    while (t--)
    {
        cin >> x >> y >> k;
        while (k && x > 1)
        {
            m = min(k, y - (x % y));
            k -= m;
            x += m;
            while (!(x % y))
                x /= y;
        }
        cout << x + k % (y - 1) << '\n';
    }
}