#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
    void dfs(int now, int now_dis, vector<int>& edges, vector<int>& vis,
             vector<int>& dis) {
        if (vis[now]) return;
        vis[now] = 1;
        dis[now] = now_dis;
        if (edges[now] != -1) dfs(edges[now], now_dis + 1, edges, vis, dis);
    }

   public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dis_a(n, INT_MAX / 2);
        vector<int> dis_b(n, INT_MAX / 2);
        vector<int> vis(n);
        dfs(node1, 0, edges, vis, dis_a);
        vis = vector<int>(n);
        dfs(node2, 0, edges, vis, dis_b);
        int mini_index = 0;
        for (int i = 1; i < n; ++i) {
            if (max(dis_a[i], dis_b[i]) <
                max(dis_a[mini_index], dis_b[mini_index])) {
                mini_index = i;
            }
        }
        if (max(dis_a[mini_index], dis_b[mini_index]) == INT_MAX / 2) return -1;
        return mini_index;
    }
};
int main() {
    vector<int> a{2, 2, 3, -1};
    Solution().closestMeetingNode(a, 0, 1);
    return 0;
}