#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
    class Disjoint_Set_Union {
       public:
        vector<int> father;
        int n;
        void init() {
            for (int i = 0; i <= n; i++) father[i] = i;
            return;
        }
        Disjoint_Set_Union(int _n) : n(_n), father(_n + 1) { init(); }
        int Find(int x) {
            return father[x] == x ? x : father[x] = Find(father[x]);
        }
        void Merge(int x, int y) {
            int fx = Find(x);
            int fy = Find(y);
            father[fy] = fx;
            return;
        }
    };

   public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> G(n, vector<int>());
        Disjoint_Set_Union d(n);
        for (auto& edge : edges) {
            G[edge[0] - 1].emplace_back(edge[1] - 1);
            G[edge[1] - 1].emplace_back(edge[0] - 1);
            d.Merge(edge[0] - 1, edge[1] - 1);
        }

        auto get_ans = [&G, n](int start) -> int {
            vector<int> vis(n), step(n);
            queue<int> q;
            vis[start] = 1;
            q.push(start);
            int ans = 0;
            while (q.size()) {
                ++ans;
                int t = q.size();
                for (int i = 0; i < t; ++i) {
                    step[q.front()] = ans;
                    for (auto& to : G[q.front()]) {
                        if (vis[to]) {
                            if (abs(step[to] - ans) != 1) return -1;
                            continue;
                        }
                        vis[to] = 1;
                        step[to] = ans + 1;
                        q.push(to);
                    }
                    q.pop();
                }
            }
            return ans;
        };
        vector<int> vis(n);
        for (int i = 0; i < n; ++i) {
            int it = get_ans(i);
            vis[d.Find(i)] = max(vis[d.Find(i)], it);
            if (it == -1) return -1;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += vis[d.Find(i)];
            vis[d.Find(i)] = 0;
        }
        return ans;
    }
};
int main() {
    vector<vector<int>> G{
        {67, 29}, {13, 29}, {77, 29}, {36, 29}, {82, 29}, {54, 29}, {57, 29},
        {53, 29}, {68, 29}, {26, 29}, {21, 29}, {46, 29}, {41, 29}, {45, 29},
        {56, 29}, {88, 29}, {2, 29},  {7, 29},  {5, 29},  {16, 29}, {37, 29},
        {50, 29}, {79, 29}, {91, 29}, {48, 29}, {87, 29}, {25, 29}, {80, 29},
        {71, 29}, {9, 29},  {78, 29}, {33, 29}, {4, 29},  {44, 29}, {72, 29},
        {65, 29}, {61, 29}};
    Solution().magnificentSets(92, G);
    return 0;
}