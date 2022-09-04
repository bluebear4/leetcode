#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
    void dfs(int now, int step, vector<int>& edges, vector<int>& vis,
             int& ans) {
        if (vis[now]) {
            ans = max(ans, step - vis[now]);
            return;
        }
        vis[now] = step;
        if (edges[now] != -1) dfs(edges[now], step + 1, edges, vis, ans);
    }

   public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> in(n);
        for (int i = 0; i < n; ++i) {
            if (edges[i] != -1) in[edges[i]]++;
        }
        vector<int> vis(n);
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (!in[i]) {
                q.push(i);
                vis[i] = 1;
            }
        }
        while (q.size()) {
            int now = q.front();
            q.pop();
            if (edges[now] == -1) continue;
            if (!--in[edges[now]]) {
                q.push(edges[now]);
                vis[edges[now]] = 1;
            }
        }
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                dfs(i, 1, edges, vis, ans);
            }
        }
        return ans;
    }
};
int main() {
    vector<int> a{3,3,4,2,3};
    Solution().longestCycle(a);
    return 0;
}