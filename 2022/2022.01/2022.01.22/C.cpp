#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid,
                                            vector<int>& pricing,
                                            vector<int>& start, int k) {
        int ways[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int n = grid.size(), m = grid[0].size();
        auto check = [&](int x, int y) {
            return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != 0;
        };
        auto check2 = [&](int x, int y) {
            return grid[x][y] >= pricing[0] && grid[x][y] <= pricing[1];
        };
        queue<pair<int, int>> q;
        q.emplace(start[0], start[1]);
        vector<vector<int>> ans;
        vector<vector<int>> vis(n, vector<int>(m));
        while (q.size()) {
            int sz = q.size();
            set<vector<int>> temp;
            for (int i = 1; i <= sz; ++i) {
                auto t = q.front();
                q.pop();
                if (vis[t.first][t.second]) continue;
                vis[t.first][t.second] = 1;
                if (check2(t.first, t.second)) {
                    temp.insert(vector<int>{grid[t.first][t.second], t.first,
                                            t.second});
                }
                for (int i = 0; i < 4; ++i) {
                    int x = t.first + ways[i][0];
                    int y = t.second + ways[i][1];
                    if (check(x, y)) {
                        q.emplace(x, y);
                    }
                }
            }
            for (auto& vec : temp) {
                ans.emplace_back(vector<int>{vec[1], vec[2]});
            }
        }
        if (ans.size() > k) ans.resize(k);
        return ans;
    }
};
// 202
// 453
// 202
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    vector<vector<int>> a{{1, 2, 0, 1}, {1, 3, 0, 1}, {0, 2, 5, 1}};
    vector<int> b{2, 5};
    vector<int> c{0, 0};
    Solution().highestRankedKItems(a, b, c, 3);
    return 0;
}