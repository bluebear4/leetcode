#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
    int dfs(vector<vector<int>>& mat, int now, int cols, vector<int>& cover) {
        int n = mat.size();
        int m = mat[0].size();
        if (now == m) return count(all(cover), 1);

        int ans = -1;
        if (cols > 0) ans = max(ans, dfs(mat, now + 1, cols - 1, cover));

        for (int i = 0; i < n; ++i) {
            if (mat[i][now] == 1) cover[i]--;
        }
        ans = max(ans, dfs(mat, now + 1, cols, cover));

        for (int i = 0; i < n; ++i) {
            if (mat[i][now] == 1) cover[i]++;
        }
        return ans;
    }

   public:
    int maximumRows(vector<vector<int>>& mat, int cols) {
        vector<int> cover(mat.size(), 1);
        return dfs(mat, 0, cols, cover);
    }
};
int main() {
    vector<vector<int>> a{{0, 0, 0}, {1, 0, 1}, {0, 1, 1}, {0, 0, 1}};

    cout << Solution().maximumRows(a, 2);
    return 0;
}