#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

class Solution {
    static constexpr int mod = 1e9 + 7;
    struct node {
        int x, y;
        node(int a, int b) : x(a), y(b) {}
    };

   public:
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 1));
        vector<node> q[100005];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                q[grid[i][j]].emplace_back(i, j);
            }
        }
        int ways[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        int ans = 0;
        for (int i = 0; i < 100005; ++i) {
            for (auto& it : q[i]) {
                for (auto& way : ways) {
                    int x = it.x + way[0];
                    int y = it.y + way[1];
                    if (x >= 0 && x < n && y >= 0 && y < m &&
                        grid[x][y] > grid[it.x][it.y]) {
                        dp[x][y] += dp[it.x][it.y];
                        dp[x][y] %= mod;
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans += dp[i][j];
                ans %= mod;
            }
        }
        return ans;
    }
};
int main() {
    vector<vector<int>> a{{1, 1}, {3, 4}};
    Solution().countPaths(a);
    return 0;
}