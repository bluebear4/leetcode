#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        for (auto& v : grid) {
            sort(v.begin(), v.end(), greater<int>{});
        }
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        for (int j = 0; j < m; ++j) {
            int temp = grid[0][j];
            for (int i = 0; i < n; ++i) {
                temp = max(temp, grid[i][j]);
            }
            ans += temp;
        }
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}