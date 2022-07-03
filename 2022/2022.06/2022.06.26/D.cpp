#include <bits/stdc++.h>
using namespace std;
#define rall(x) x.rbegin(), x.rend()
class Solution {
#define all(x) x.begin(), x.end()

    void dfs(int now, vector<vector<int>> &G, vector<int> &xo,
             vector<int> &dep) {
        for (auto &son : G[now]) {
            if (dep[son]) continue;
            dep[son] = dep[now] + 1;
            dfs(son, G, xo, dep);
            xo[now] ^= xo[son];
        }
    }

   public:
    int minimumScore(vector<int> &nums, vector<vector<int>> &edges) {
        int n = nums.size();
        vector<vector<int>> G(n);
        for (auto &edge : edges) {
            G[edge[0]].emplace_back(edge[1]);
            G[edge[1]].emplace_back(edge[0]);
        }

        vector<int> xo(n);
        for (int i = 0; i < n; ++i) xo[i] = nums[i];
        vector<int> dep(n);
        dep[0] = 1;
        dfs(0, G, xo, dep);

        int ans = 1e9;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                int x, y;
                if (dep[edges[i][0]] > dep[edges[i][1]]) {
                    x = edges[i][0];
                } else {
                    x = edges[i][1];
                }
                if (dep[edges[j][0]] > dep[edges[j][1]]) {
                    y = edges[j][0];
                } else {
                    y = edges[j][1];
                }
                ans = min(ans, max({xo[0] ^ xo[x] ^ xo[y], xo[x], xo[y]}) -
                                   min({xo[0] ^ xo[x] ^ xo[y], xo[x], xo[y]}));
            }
        }
        return ans;
    }
};
int main() {
    vector<int> a{1, 5, 5, 4, 11};
    vector<vector<int>> b{{0, 1}, {1, 2}, {4, 3}, {1, 3}};
    Solution().minimumScore(a, b);
    return 0;
}