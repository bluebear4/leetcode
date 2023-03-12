#include <bits/stdc++.h>
using namespace std;
class Solution {
    struct node {
        int x, y, time;
        bool operator<(const node& r) const { return time < r.time; }
        bool operator>(const node& r) const { return time > r.time; }
    };

   public:
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[1][0] > 1 && grid[0][1] > 1) return -1;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        dis[0][0] = 0;
        priority_queue<node, vector<node>, greater<node>> pq;
        pq.push({0, 0, 0});
        int ways[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        while (!pq.empty()) {
            node now = pq.top();
            pq.pop();
            for (auto& way : ways) {
                int x = now.x + way[0];
                int y = now.y + way[1];
                if (x >= 0 && x < n && y >= 0 && y < m) {
                    int nxt =
                        max(now.time + 1,
                            grid[x][y] + ((now.time + grid[x][y]) % 2 == 0));

                    if (dis[x][y] > nxt) {
                        pq.push({x, y, nxt});
                        dis[x][y] = nxt;
                    }
                }
            }
        }
        assert(dis.back().back() != INT_MAX);
        return dis.back().back();
    }
};
int main() {
    vector<vector<int>> a{{0, 1, 3, 2}, {5, 1, 2, 5}, {4, 3, 8, 6}};
    Solution().minimumTime(a);
    return 0;
}