#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
    int dfs(int now, vector<vector<int>> &edges, const string &s, int &ans) {
        multiset<int> mset;

        for (auto &son : edges[now]) {
            if (s[now] != s[son]) {
                mset.insert(dfs(son, edges, s, ans));
            } else {
                dfs(son, edges, s, ans);
            }
        }

        switch (mset.size()) {
            case 0:
                ans = max(ans, 1);
                return 1;
            default:
                ans = max(ans, 1 + *mset.rbegin() + *(++mset.rbegin()));
            case 1:
                ans = max(ans, 1 + *mset.rbegin());
                return 1 + *mset.rbegin();
        }
        return -1;
    }

   public:
    int longestPath(vector<int> &parent, string s) {
        int n = parent.size();
        vector<vector<int>> edges(n, vector<int>());
        for (int i = 1; i < n; ++i) {
            edges[parent[i]].emplace_back(i);
        }
        int ans = 0;
        dfs(0, edges, s, ans);
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}