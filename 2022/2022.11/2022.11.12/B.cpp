#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int countGoodStrings(int low, int high, int zero, int one) {
        static int mod = 1e9 + 7;
        vector<int> dp(high + 1);
        dp[0] = 1;
        for (int i = 0; i < dp.size(); ++i) {
            if (i + zero < dp.size()) {
                dp[i + zero] += dp[i];
                dp[i + zero] %= mod;
            }
            if (i + one < dp.size()) {
                dp[i + one] += dp[i];
                dp[i + one] %= mod;
            }
        }
        return accumulate(dp.begin() + low, dp.end(), 0ll) % mod;
    }
};

int main() {
    // Solution()
    return 0;
}