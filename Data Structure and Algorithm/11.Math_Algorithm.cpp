#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

//-------------------------
// 1. Sieve of Eratosthenes
vector<bool> sieve(int n) {
    vector<bool> prime(n+1, true);
    prime[0] = prime[1] = false;
    for (int p = 2; p*p <= n; p++) {
        if (prime[p]) {
            for (int i = p*p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }
    return prime;
}

//-------------------------
// 2. Fermat's Primality Test
long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

bool fermatTest(int n, int k=5) {
    if (n < 4) return (n == 2 || n == 3);
    for (int i = 0; i < k; i++) {
        int a = 2 + rand() % (n - 3);
        if (modExp(a, n-1, n) != 1) return false;
    }
    return true;
}

//-------------------------
// 3. Miller-Rabin Primality Test
bool millerTest(long long d, long long n, int a) {
    long long x = modExp(a, d, n);
    if (x == 1 || x == n-1) return true;

    while (d != n-1) {
        x = (x * x) % n;
        d <<= 1;
        if (x == 1) return false;
        if (x == n-1) return true;
    }
    return false;
}

bool isPrimeMillerRabin(long long n, int k=5) {
    if (n < 4) return (n == 2 || n == 3);
    if (n % 2 == 0) return false;

    long long d = n - 1;
    while ((d & 1) == 0) d >>= 1;

    for (int i = 0; i < k; i++) {
        int a = 2 + rand() % (n - 3);
        if (!millerTest(d, n, a)) return false;
    }
    return true;
}

//-------------------------
// 4. Modular Inverse using Extended Euclidean
long long gcdExtended(long long a, long long b, long long &x, long long &y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    long long x1, y1;
    long long gcd = gcdExtended(b % a, a, x1, y1);
    x = y1 - (b/a) * x1;
    y = x1;
    return gcd;
}

long long modInverse(long long a, long long m) {
    long long x, y;
    long long g = gcdExtended(a, m, x, y);
    if (g != 1) return -1; // Inverse doesn't exist
    else {
        x = (x % m + m) % m;
        return x;
    }
}

//-------------------------
// 5. Fast Exponentiation (PowMod)
long long powMod(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

//-------------------------
// 6. GCD and LCM
long long gcdEuclid(long long a, long long b) {
    if (b == 0) return a;
    return gcdEuclid(b, a % b);
}
long long lcm(long long a, long long b) {
    return (a / gcdEuclid(a, b)) * b;
}

//-------------------------
// Demo
int main() {
    // Sieve demo
    int n = 30;
    auto primes = sieve(n);
    cout << "Primes up to " << n << ": ";
    for (int i = 2; i <= n; i++) if (primes[i]) cout << i << " ";
    cout << "\n";

    // Fermat test demo
    int num = 31;
    cout << "Fermat Test for " << num << ": " << (fermatTest(num) ? "Probably Prime" : "Composite") << "\n";

    // Miller-Rabin demo
    cout << "Miller-Rabin Test for " << num << ": " << (isPrimeMillerRabin(num) ? "Probably Prime" : "Composite") << "\n";

    // Modular inverse demo
    long long a = 3, m = 11;
    cout << "Modular inverse of " << a << " mod " << m << " is " << modInverse(a, m) << "\n";

    // PowMod demo
    cout << "PowMod(2,10,1000): " << powMod(2, 10, 1000) << "\n";

    // GCD and LCM demo
    long long x = 24, y = 36;
    cout << "GCD(" << x << "," << y << ") = " << gcdEuclid(x,y) << "\n";
    cout << "LCM(" << x << "," << y << ") = " << lcm(x,y) << "\n";

    return 0;
}
