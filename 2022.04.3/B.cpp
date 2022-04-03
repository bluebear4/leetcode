#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rall(x) x.rbegin(), x.rend()
class Solution {
#define all(x) x.begin(), x.end()
   public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> in;
        for (auto& match : matches) {
            in[match[0]];
            in[match[1]]++;
        }
        vector<vector<int>> ans(2, vector<int>());
        for (auto& [u, v] : in) {
            if (v <= 1) {
                ans[v].emplace_back(u);
            }
        }
        sort(all(ans[0]));
        sort(all(ans[1]));
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}