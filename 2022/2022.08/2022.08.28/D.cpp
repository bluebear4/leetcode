#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
    vector<int> topSort(vector<vector<int>>& edges, int k) {
        vector<int> in(k + 1);
        vector<vector<int>> G(k + 1, vector<int>{});
        for (auto& edge : edges) {
            in[edge[1]]++;
            G[edge[0]].emplace_back(edge[1]);
        }
        queue<int> q;
        for (int i = 1; i <= k; ++i) {
            if (!in[i]) q.push(i);
        }
        vector<int> ret;
        while (q.size()) {
            int t = q.front();
            q.pop();
            ret.push_back(t);
            for (auto& it : G[t]) {
                if (!--in[it]) q.push(it);
            }
        }
        return ret;
    }

   public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions,
                                    vector<vector<int>>& colConditions) {
        vector<int> row = topSort(rowConditions, k);
        vector<int> col = topSort(colConditions, k);
        if (row.size() < k || col.size() < k) return vector<vector<int>>{};
        vector<vector<int>> ans(k, vector<int>(k));
        unordered_map<int, pair<int, int>> pos;
        for (int i = 0; i < row.size(); ++i) {
            pos[row[i]].first = i;
        }
        for (int j = 0; j < col.size(); ++j) {
            pos[col[j]].second = j;
        }
        for (auto& [k, v] : pos) {
            ans[v.first][v.second] = k;
        }
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}