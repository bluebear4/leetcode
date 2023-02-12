#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int bestClosingTime(string s) {
        int n = s.length();

        vector<vector<int>> dp(n + 2, vector<int>(2, INT_MAX / 2));
        dp[0][1] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = dp[i - 1][1] + (s[i - 1] == 'Y');
            dp[i][1] = dp[i - 1][1] + (s[i - 1] == 'N');
        }
        dp.back()[0] = dp[n][1];
        for (int i = n, now = 0; i >= 1; --i) {
            now += (s[i - 1] == 'Y');
            dp[i][0] += now;
        }
        int ans = 0;
        for (int i = 1; i < dp.size(); ++i) {
            if (dp[i][0] < dp[ans+1][0]) {
                ans = i - 1;
            }
        }
        return ans;
    }
};
int main() {
    Solution().bestClosingTime("NNNNN");
    return 0;
}