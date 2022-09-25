#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
// ....
// .EE.
// O.E.
// ....
class Solution {
    int dfs(int x, int y, int way, vector<vector<vector<int>>>& dp,
            vector<string>& plate) {
        static int ways[4][2] = {
            {1, 0}, {0, -1}, {-1, 0}, {0, 1}};  //顺时针顺序 ↓ ← ↑ →

        if (x < 0 || x >= plate.size() || y < 0 || y >= plate[0].size())
            return 1e9;                                 //出界
        if (dp[x][y][way] < 1e9) return dp[x][y][way];  //记忆化

        if (dp[x][y][way] > 1e9) return dp[x][y][way];
        dp[x][y][way] = 1e9 + 1;

        if (plate[x][y] == 'O') return dp[x][y][way] = 0;  //入洞
        int nxtWay = way;
        if (plate[x][y] == 'E') nxtWay = (way + 1) % 4;  //顺时针转
        if (plate[x][y] == 'W') nxtWay = (way + 3) % 4;  //逆时针转
        return dp[x][y][way] =
                   dfs(x + ways[nxtWay][0], y + ways[nxtWay][1], nxtWay, dp,
                       plate) +
                   1;  //记忆化
    }

   public:
    vector<vector<int>> ballGame(int num, vector<string>& plate) {
        int n = plate.size(), m = plate[0].size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(4, 1e9)));
        set<vector<int>> ans;
        // 4*5
        for (int i = 1; i + 1 < n; ++i) {
            if (plate[i][0] == '.' && dfs(i, 0, 3, dp, plate) <= num) {
                ans.insert(vector<int>{i, 0});
            }
            if (plate[i][m - 1] == '.' && dfs(i, m - 1, 1, dp, plate) <= num) {
                ans.insert(vector<int>{i, m - 1});
            }
        }

        for (int j = 1; j + 1 < m; ++j) {
            if (plate[0][j] == '.' && dfs(0, j, 0, dp, plate) <= num) {
                ans.insert(vector<int>{0, j});
            }
            if (plate[n - 1][j] == '.' && dfs(n - 1, j, 2, dp, plate) <= num) {
                ans.insert(vector<int>{n - 1, j});
            }
        }

        return vector<vector<int>>{ans.begin(), ans.end()};
    }
};
int main() {
    // ....
    // .EE.
    // O.E.
    // ....
    vector<string> a{"....", ".EE.", "O.E.", "...."};
    Solution().ballGame(6, a);
    return 0;
}