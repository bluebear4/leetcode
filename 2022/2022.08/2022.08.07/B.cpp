#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rall(x) x.rbegin(), x.rend()
class Solution {
#define all(x) x.begin(), x.end()
    void dfs(int now, vector<vector<int>>& G, unordered_set<int>& restricted,
             vector<int>& vis) {
        if (vis[now] || restricted.count(now)) return;
        vis[now] = 1;
        for (auto& it : G[now]) {
            dfs(it, G, restricted, vis);
        }
    }

   public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& r) {
        vector<vector<int>> G(n, vector<int>());
        for (auto& edge : edges) {
            G[edge[0]].emplace_back(edge[1]);
            G[edge[1]].emplace_back(edge[0]);
        }
        vector<int> vis(n);
        unordered_set restricted(all(r));
        dfs(0, G, restricted, vis);
        return count(all(vis), 1);
    }
};
int main() {
    // Solution()
    return 0;
}