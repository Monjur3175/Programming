#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }

        vector<long long> dp(N, 0);
        dp[0] = 1;

        for (int i = 1; i < N; ++i) {
            if (A[i] == 0) {
                dp[i] = dp[i-1];
            } else {
                dp[i] = (dp[i-1] + dp[i-1] - dp[max(i - A[i] - 1, 0)]) % MOD;
            }
        }

        cout << dp[N-1] << "\n";
    }
    return 0;
}
