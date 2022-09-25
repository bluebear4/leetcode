#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int unSuitability(vector<int>& operate) {
        int n = operate.size();
        vector<vector<int>> dp(n, vector<int>(2005));
        dp[0][1000 + operate[0]] = 1;
        dp[0][1000 - operate[0]] = 1;
        for (int i = 1; i < n; ++i) {
            dp[i][1000 + operate[0]] = 1;
            dp[i][1000 - operate[0]] = 1;
            for (int j = operate[0]; j + operate[0] < 2005; ++j) {
                dp[i][j + operate[0]] = dp[i - 1][j];
                dp[i][j - operate[0]] = dp[i - 1][j];
            }
            for (int j = 0; j < dp[i].size(); ++j) {
                if (dp[i][j]) {
                    cout << j << ",";
                }
            }
            cout << endl;
        }
        return 1;
        // 5 -5 2 3 8 -8 -2 -3
    }
};
int main() {
    vector<int> a{5, 3, 7};
    Solution().unSuitability(a);
    return 0;
}