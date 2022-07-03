#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

class Solution {
    using ll = long long;
    static constexpr ll mod = 1e9 + 7;
    // ll dp[10005][7][7];
    ll dp[10][7][7];

   public:
    int distinctSequences(int n) {
        for (int i = 0; i <= n; ++i) {
            for (int j = 1; j <= 6; ++j) {
                for (int k = 1; k <= 6; ++k) {
                    dp[i][j][k] = 0;
                }
            }
        }
        dp[0][0][0] = 1;
        ll ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= 6; ++j) {
                for (int k = 0; k <= 6; ++k) {
                    for (int l = 1; l <= 6; ++l) {
                        if (k == 0 || (__gcd(l, k) == 1 && l != j && l != k)) {
                            dp[i][k][l] += dp[i - 1][j][k];
                            dp[i][k][l] %= mod;
                        }
                    }
                }
            }
        }
        for (int j = 0; j <= 6; ++j) {
            for (int k = 0; k <= 6; ++k) {
                ans += dp[n][j][k];
                ans %= mod;
            }
        }
        return ans;
    }
};
int main() {
    Solution().distinctSequences(2);
    return 0;
}