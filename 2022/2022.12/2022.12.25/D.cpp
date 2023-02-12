#include <bits/stdc++.h>
using namespace std;
class Solution {
    // long long dp1[1005][1005];
    // long long dp2[1005][1005];
    static constexpr int mod = 1e9 + 7;
    long long ksm(long long a, long long n = mod - 2, long long m = mod) {
        long long ans = 1;
        a %= m;
        while (n) {
            if (n & 1) ans = ans * a % m;
            a = a * a % m;
            n >>= 1;
        }
        return ans;
    }

   public:
    int countPartitions(vector<int>& nums, int k) {
        if (accumulate(nums.begin(), nums.end(), 0ll) < 2 * k) return 0;
        int n = nums.size();
        // for (int i = 0; i <= n; ++i) {
        //     for (int j = 0; j <= k; ++j) {
        //         dp1[i][j] = dp2[i][j] = 0;
        //     }
        // }
        vector<vector<long long>> dp(n, vector<long long>(k + 1));

        // dp1[i][j] 表示前i个 子序列和为j 的 方案数
        for (int i = 0; i < n; ++i) {
            // 自己一个作为子序列
            dp[i][min(k, nums[i])]++;
            for (int j = 0; j <= k; ++j) {
                if (i) {
                    // 继承上一个子序列
                    dp[i][j] += dp[i - 1][j];
                    dp[i][j] %= mod;
                    // 叠加 成为新的子序列
                    dp[i][min(k, nums[i] + j)] += dp[i - 1][j];
                    dp[i][min(k, nums[i] + j)] %= mod;
                }
            }
        }

        //全子序列 去除空 和 本身
        long long ans = ksm(2, n) - 2;
        for (int i = 0; i < k; ++i) {
            ans -= 2 * dp.back()[i];
            ans %= mod;
            ans += mod;
            ans %= mod;
        }
        return ans;
    }
};
int main() {
    vector<int> a{96, 40, 22, 98, 9, 97, 45, 22, 79, 57, 95, 62};
    Solution().countPartitions(a, 505);
    return 0;
}