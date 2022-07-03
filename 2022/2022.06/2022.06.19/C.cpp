#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int longestSubsequence(string s, int k) {
        int n = s.length();
        vector<int> dp(n + 1, 1e9 + 7);
        dp[0] = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = n; j >= 1; --j) {
                dp[j] = min(dp[j], dp[j - 1] * 2 + (s[i] - '0'));
                if (dp[j] <= k) {
                    ans = max(ans, j);
                }
            }
        }
        return ans;
    }
};
int main() {
    Solution().longestSubsequence("1001010", 5);
    return 0;
}