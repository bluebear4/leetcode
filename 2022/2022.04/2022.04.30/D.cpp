#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
    using pii = pair<int, int>;

   public:
    int maximumMinutes(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        auto ok = [&n, &m](int x, int y) {
            return x >= 0 && x < n && y >= 0 && y < m;
        };

        auto check = [&n, &m, &ok](int x, vector<vector<int>> grid) mutable {
            queue<pii> q4Fire;
            queue<pii> q4Human;
            vector<vector<int>> vis(n, vector<int>(m, 0));
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (grid[i][j] == 1) {
                        q4Fire.emplace(i, j);
                    }
                }
            }
            while (x-- && q4Fire.size()) {
                int sz = q4Fire.size();
                for (int i = 0; i < sz; ++i) {
                    auto t = q4Fire.front();
                    q4Fire.pop();
                    int ways[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
                    for (auto& way : ways) {
                        int x = t.first + way[0];
                        int y = t.second + way[1];
                        if (ok(x, y) && grid[x][y] == 0) {
                            grid[x][y] = 1;
                            q4Fire.emplace(x, y);
                        }
                    }
                }
            }

            if (grid[0][0] == 0) q4Human.emplace(0, 0);
            while (q4Human.size()) {
                int sz = q4Fire.size();
                bool fireHouse = false;
                for (int i = 0; i < sz; ++i) {
                    auto t = q4Fire.front();
                    q4Fire.pop();
                    int ways[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
                    for (auto& way : ways) {
                        int x = t.first + way[0];
                        int y = t.second + way[1];
                        if (ok(x, y) && grid[x][y] == 0) {
                            if (x == n - 1 && y == m - 1) fireHouse = true;
                            grid[x][y] = 1;
                            q4Fire.emplace(x, y);
                        }
                    }
                }
                {
                    int sz = q4Human.size();
                    for (int i = 0; i < sz; ++i) {
                        auto t = q4Human.front();
                        q4Human.pop();
                        if (vis[t.first][t.second]) continue;
                        vis[t.first][t.second] = 1;
                        int ways[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
                        for (auto& way : ways) {
                            int x = t.first + way[0];
                            int y = t.second + way[1];
                            if (ok(x, y)) {
                                if (x == n - 1 && y == m - 1 &&
                                    (fireHouse || grid[x][y] == 0))
                                    return true;
                                if (grid[x][y] == 0) q4Human.emplace(x, y);
                            }
                        }
                    }
                }
            }
            return false;
        };
        int ans = -1;
        int l = 0, r = 1e9, mid;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(mid, grid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
int main() {
    // vector<vector<int>> a{{0, 2, 0, 0, 0, 0, 0},
    //                       {0, 0, 0, 2, 2, 1, 0},
    //                       {0, 2, 0, 0, 1, 2, 0},
    //                       {0, 0, 2, 2, 2, 0, 2},
    //                       {0, 0, 0, 0, 0, 0, 0}};
    vector<vector<int>> a{{0, 2, 0, 0, 1},
                          {0, 2, 0, 2, 2},
                          {0, 2, 0, 0, 0},
                          {0, 0, 2, 2, 0},
                          {0, 0, 0, 0, 0}};
    Solution().maximumMinutes(a);
    return 0;
}