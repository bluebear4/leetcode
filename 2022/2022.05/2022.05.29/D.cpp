#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
    struct node {
        int i, j, k;
        bool operator<(const node& r) const { return k < r.k; }
    };
    const static inline int ways[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

   public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m));
        priority_queue<node> pq;
        pq.push(node{0, 0, n * m});
        while (pq.size()) {
            auto t = pq.top();
            pq.pop();
            if (vis[t.i][t.j]) continue;
            vis[t.i][t.j] = 1;
            if (t.i == n - 1 && t.j == m - 1) return n * m - t.k;
            for (auto& way : ways) {
                int i = t.i + way[0];
                int j = t.j + way[1];
                if (i >= 0 && i < n && j >= 0 && j < m && t.k >= grid[i][j]) {
                    pq.push(node{i, j, t.k - grid[i][j]});
                }
            }
        }
        return -1;
    }
};
int main() {
    vector<vector<int>> a{{0, 1, 0, 0, 0}, {0, 1, 0, 1, 0}, {0, 0, 0, 1, 0}};

    Solution().minimumObstacles(a);
    return 0;
}