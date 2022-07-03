#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j || j == n - 1 - i) {
                    if (grid[i][j] == 0) return false;

                } else if (grid[i][j] != 0) {
                    return false;
                }
            }
        }
        return true;
    }
};
int main() {
    return 0;
}