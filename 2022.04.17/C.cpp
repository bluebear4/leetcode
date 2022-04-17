#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
    using pii = pair<int, int>;

   public:
    int maxTrailingZeros(vector<vector<int>>& grid) {
        vector<pii> pair25(1001, make_pair(0, 0));
        for (int i = 0; i <= 1000; ++i) {
            int num = i;

            while (num % 2 == 0 && num > 0) {
                pair25[i].first++;
                num /= 2;
            }

            while (num % 5 == 0 && num > 0) {
                pair25[i].second++;
                num /= 5;
            }
        }
        int n = grid.size(), m = grid[0].size(), ans = 0;

        vector<vector<pii>> rowsum(n + 1, vector<pii>(m + 1, make_pair(0, 0)));
        vector<vector<pii>> colsum(n + 1, vector<pii>(m + 1, make_pair(0, 0)));

        auto getans = [](const pii& x) { return min(x.first, x.second); };
        auto add = [](const pii& x, const pii& y) {
            return make_pair(x.first + y.first, x.second + y.second);
        };
        auto minus = [](const pii& x, const pii& y) {
            return make_pair(x.first - y.first, x.second - y.second);
        };
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                rowsum[i][j] = pair25[grid[i - 1][j - 1]];
                colsum[i][j] = pair25[grid[i - 1][j - 1]];
            }
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                rowsum[i][j].first += rowsum[i][j - 1].first;
                rowsum[i][j].second += rowsum[i][j - 1].second;

                colsum[i][j].first += colsum[i - 1][j].first;
                colsum[i][j].second += colsum[i - 1][j].second;
            }
        }

        for (int j = 1; j <= m; ++j) ans = max(ans, getans(colsum[n][j]));
        for (int i = 1; i <= n; ++i) ans = max(ans, getans(rowsum[i].back()));

        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                const pii& up = colsum[i][j + 1];
                const pii& left = rowsum[i + 1][j];
                const pii& down = minus(colsum[n][j + 1], colsum[i + 1][j + 1]);
                const pii& right =
                    minus(rowsum[i + 1][m], rowsum[i + 1][j + 1]);
                int temp = getans(add(add(up, left), pair25[grid[i][j]]));
                ans = max(ans, temp);
                temp = getans(add(add(up, right), pair25[grid[i][j]]));
                ans = max(ans, temp);
                temp = getans(add(add(down, left), pair25[grid[i][j]]));
                ans = max(ans, temp);
                temp = getans(add(add(down, right), pair25[grid[i][j]]));
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