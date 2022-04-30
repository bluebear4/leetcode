#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
    int dp[12][100005];
    int path[12][100005];

   public:
    vector<int> maximumBobPoints(int n, vector<int>& aliceArrows) {
        //前i环 用了j箭
        int row = 0, col = 0;
        for (int i = 1; i < 12; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (dp[i - 1][j] > dp[i][j]) {
                    dp[i][j] = dp[i - 1][j];
                    path[i][j] = j;
                }
                if (j + aliceArrows[i] + 1 <= n &&
                    dp[i - 1][j] + i > dp[i][j + aliceArrows[i] + 1]) {
                    dp[i][j + aliceArrows[i] + 1] = dp[i - 1][j] + i;
                    path[i][j + aliceArrows[i] + 1] = j;
                }
                if (dp[i][j] > dp[row][col]) {
                    row = i, col = j;
                }
            }
        }
        vector<int> ans(12);
        while (row > 0) {
            if (path[row][col] != col) {
                ans[row] = aliceArrows[row] + 1;
            }
            col = path[row][col];
            --row;
        }
        ans[0] = n - accumulate(ans.begin(), ans.end(), 0);
        return ans;
    }
};
int main() {
    vector<int> a{0, 0, 1, 1, 3, 0, 0, 0, 0, 2, 0, 0};
    Solution().maximumBobPoints(7, a);
    return 0;
}