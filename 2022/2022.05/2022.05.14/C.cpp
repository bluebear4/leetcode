#include <bits/stdc++.h>
using namespace std;
#define rall(x) x.rbegin(), x.rend()
class Solution {
#define all(x) x.begin(), x.end()
   public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(all(tiles));
        int n = tiles.size();
        vector<int> sum(n);
        for (int i = 0; i < n; ++i) {
            sum[i] = tiles[i][1] - tiles[i][0] + 1;
            if (i) sum[i] += sum[i - 1];
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int len = carpetLen + tiles[i][0] - 1;
            int j = upper_bound(all(tiles), vector<int>{0, len},
                                [](const vector<int>& x, const vector<int>& y) {
                                    return x[1] < y[1];
                                }) -
                    tiles.begin() - 1;
            int temp = 0;
            if (j >= i) {
                if (i) {
                    temp += sum[j] - sum[i - 1];
                } else {
                    temp += sum[j];
                }
            }
            if (j + 1 < n) temp += max(len - tiles[j + 1][0] + 1, 0);
            ans = max(ans, temp);
        }
        return ans;
    }
};
int main() {
    vector<vector<int>> a{{1, 5}, {10, 11}, {12, 18}, {20, 25}, {30, 32}};
    Solution().maximumWhiteTiles(a, 10);
    return 0;
}