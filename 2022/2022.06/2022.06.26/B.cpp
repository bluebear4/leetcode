#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
    static constexpr int mod = 1e9 + 7;
    using ll = long long;

   public:
    int countHousePlacements(int n) {
        vector<vector<ll>> dp(n + 1, vector<ll>(4));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] =
                (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3]) %
                mod;
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
            dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
            dp[i][3] = (dp[i - 1][0]) % mod;
        }
        return (dp[n][0] + dp[n][1] + dp[n][2] + dp[n][3]) % mod;
    }
};
int main() {
    // Solution()
    return 0;
}