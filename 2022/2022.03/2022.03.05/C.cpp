#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> edge(n, vector<int>{});
        vector<int> in(n);
        for (auto& it : edges) {
            edge[it[0]].emplace_back(it[1]);
            in[it[1]]++;
        }
        vector<set<int>> temp(n, set<int>{});
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (in[i] == 0) {
                q.push(i);
            }
        }
        while (q.size()) {
            int t = q.front();
            q.pop();
            for (auto& to : edge[t]) {
                for (auto& it : temp[t]) {
                    temp[to].insert(it);
                }
                temp[to].insert(t);
                if (--in[to] == 0) {
                    q.push(to);
                }
            }
        }
        vector<vector<int>> ans(n, vector<int>{});
        for (int i = 0; i < n; ++i) {
            ans[i] = vector<int>{temp[i].begin(), temp[i].end()};
        }
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}