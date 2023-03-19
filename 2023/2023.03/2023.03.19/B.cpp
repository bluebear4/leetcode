#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pair<int, int>> pos(n * n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                pos[grid[i][j]] = make_pair(i, j);
            }
        }
        if (pos[0] != make_pair(0, 0)) return false;
        for (int i = 1; i < n * n; ++i) {
            int a = abs(pos[i].first - pos[i - 1].first);
            int b = abs(pos[i].second - pos[i - 1].second);
            if (a > b) swap(a, b);
            if (a != 1 || b != 2) return false;
        }
        return true;
    }
};
int main() { return 0; }