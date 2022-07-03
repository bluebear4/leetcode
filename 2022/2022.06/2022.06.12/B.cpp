#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rall(x) x.rbegin(), x.rend()
class Solution {
#define all(x) x.begin(), x.end()
   public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 1e9));
        for (int j = 0; j < m; ++j) {
            dp[0][j] = grid[0][j];
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int j2 = 0; j2 < m; ++j2) {
                    // i-1,j i,j2
                    dp[i][j2] = min(
                        dp[i][j2], dp[i - 1][j] + moveCost[grid[i - 1][j]][j2] +
                                       grid[i][j2]);
                }
            }
        }
        return *min_element(all(dp.back()));
    }
};
int main() {
    // Solution()
    return 0;
}