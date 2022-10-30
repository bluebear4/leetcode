#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int maxSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for (int i = 0; i + 2 < n; ++i) {
            for (int j = 0; j + 2 < m; ++j) {
                int temp = 0;
                temp += grid[i][j];
                temp += grid[i][j + 1];
                temp += grid[i][j + 2];
                temp += grid[i + 1][j + 1];
                temp += grid[i + 2][j];
                temp += grid[i + 2][j + 1];
                temp += grid[i + 2][j + 2];
                ans = max(ans, temp);
            }
        }
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}