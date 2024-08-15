#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Function to precompute prime numbers using Sieve of Eratosthenes
vector<bool> sieve(ll max_sum)
{
    vector<bool> is_prime(max_sum + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i * i <= max_sum; ++i)
    {
        if (is_prime[i])
        {
            for (ll j = i * i; j <= max_sum; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

void solution()
{

    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    // Find the maximum possible sum
    ll max_sum = 2 * *max_element(v.begin(), v.end());

    // Precompute prime numbers up to max_sum
    vector<bool> is_prime = sieve(max_sum);

    bool found = false;
    for (ll i = 0; i < n; ++i)
    {
        for (ll j = i + 1; j < n; ++j)
        {
            if (!is_prime[v[i] + v[j]])
            {
                cout << i + 1 << " " << j + 1 << endl;
                found = true;
                break;
            }
        }
        if (found)
            break;
    }
    if (!found)
    {
        cout << -1 << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}