#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
    using pii = pair<int, int>;

   public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n = scores.size();
        vector<set<pii, greater<pii>>> maxx(n, set<pii, greater<pii>>());
        for (auto& it : edges) {
            maxx[it[0]].emplace(scores[it[1]], it[1]);
            maxx[it[1]].emplace(scores[it[0]], it[0]);
        }
        int ans = -1;
        for (auto& it : edges) {
            int u = it[0], v = it[1];
            for (auto& nodeA : maxx[u]) {
                if (nodeA.second == u || nodeA.second == v) continue;
                bool ok = false;
                for (auto& nodeB : maxx[v]) {
                    if (nodeB.second == u || nodeB.second == v ||
                        nodeB.second == nodeA.second)
                        continue;
                    ans = max(
                        ans, scores[u] + scores[v] + nodeA.first + nodeB.first);
                    ok = true;
                    break;
                }
                if (ok) break;
            }
            for (auto& nodeB : maxx[v]) {
                if (nodeB.second == u || nodeB.second == v) continue;
                bool ok = false;
                for (auto& nodeA : maxx[u]) {
                    if (nodeA.second == u || nodeA.second == v ||
                        nodeB.second == nodeA.second)
                        continue;
                    ans = max(
                        ans, scores[u] + scores[v] + nodeA.first + nodeB.first);
                    ok = true;
                    break;
                }
                if (ok) break;
            }
        }
        return ans;
    }
};
int main() {
    vector<int> a{5, 2, 9, 8, 4};
    vector<vector<int>> b{{0, 1}, {1, 2}, {2, 3}, {0, 2}, {1, 3}, {2, 4}};
    Solution().maximumScore(a, b);
    return 0;
}