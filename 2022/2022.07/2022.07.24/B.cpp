#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()
class Solution {
   public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> cnt;
        int n = grid.size(), ans = 0;
        for (int i = 0; i < n; ++i) {
            cnt[grid[i]]++;
        }
        for (int j = 0; j < n; ++j) {
            vector<int> temp;
            for (int i = 0; i < n; ++i) {
                temp.push_back(grid[i][j]);
            }
            if (cnt.count(temp)) ans += cnt[temp];
        }
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}