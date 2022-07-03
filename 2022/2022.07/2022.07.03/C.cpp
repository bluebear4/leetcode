#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
    static constexpr int mod = 1e9 + 7;

   public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        // f[n] = f[n-1]+(f[n-delay]-f[n-forget]);
        vector<int> dp(n + 1, 1);
        dp[0] = 0;
        for (int i = delay + 1; i <= n; ++i) {
            if (i >= forget) {
                dp[i] =
                    ((dp[i - 1] - dp[i - forget] + dp[i - delay]) % mod + mod) %
                    mod;
            } else {
                dp[i] = ((dp[i - 1] + dp[i - delay]) % mod + mod) % mod;
            }
        }
        return (dp.back() - dp[n - forget] + mod) % mod;
    }
};
int main() {
    Solution().peopleAwareOfSecret(4, 1, 3);
    return 0;
}