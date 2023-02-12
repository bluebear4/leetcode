#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<multiset<int, greater<int>>> G(n);
        for (auto& edge : edges) {
            G[edge[0]].insert(vals[edge[1]]);
            G[edge[1]].insert(vals[edge[0]]);
        }
        int ans = INT_MIN;
        for (int i = 0; i < n; ++i) {
            ans =
                max(ans,
                    [i, k, &vals](const multiset<int, greater<int>>& p) -> int {
                        int sum = vals[i];
                        auto it = p.begin();
                        for (int j = 0; j < k && it != p.end(); ++j, ++it) {
                            if (*it < 0) break;
                            sum += *it;
                        }
                        return sum;
                    }(G[i]));
        }
        return ans;
    }
};

int main() { return 0; }