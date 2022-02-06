#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
    int dp[200005][2];
    int dp2[200005][2];

   public:
    int minimumTime(string s) {
        s = "#" + s;
        int n = s.length();
        // vector<vector<int>> dp(n + 1, vector<int>(2));
        // 开大Vector会超时
        // 0:always first 1
        for (int i = 1, last = -1; i < n; ++i) {
            dp[i][0] = dp[i - 1][0] + 1;
            if (s[i] == '0') {
                dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]);
            } else {
                dp[i][1] = min(dp[i - 1][0] + 1, dp[i - 1][1] + 2);
            }
        }
        int ans = INT_MAX;
        // vector<vector<int>> dp2(n + 1, vector<int>(2));
        for (int i = n - 1; i >= 1; --i) {
            dp2[i][0] = dp2[i + 1][0] + 1;
            if (s[i] == '0') {
                dp2[i][1] = min(dp2[i + 1][0], dp2[i + 1][1]);
            } else {
                dp2[i][1] = min(dp2[i + 1][0] + 1, dp2[i + 1][1] + 2);
            }
            ans = min(ans, min(dp[i - 1][0], dp[i - 1][1]) +
                               min(dp2[i][0], dp2[i][1]));
        }
        return ans;
    }
};
int main() {
    Solution().minimumTime("1");
    return 0;
}