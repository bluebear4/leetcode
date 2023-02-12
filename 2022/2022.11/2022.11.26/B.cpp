#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> row(n, vector<int>(2));
        vector<vector<int>> col(m, vector<int>(2));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                row[i][grid[i][j] == 1]++;
                col[j][grid[i][j] == 1]++;
            }
        }
        vector<vector<int>> ans(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans[i][j] = row[i][1] + col[j][1] - row[i][0] - col[j][0];
            }
        }
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}