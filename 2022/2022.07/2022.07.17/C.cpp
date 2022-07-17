#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
class Solution {
   public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums,
                                       vector<vector<int>>& queries) {
        int n = nums.size();
        int m = nums[0].length();
        vector<vector<int>> a(m + 1, vector<int>(n));
        //最右m位 第[i]位排名为x

        for (int i = 0; i <= m; ++i) {
            iota(all(a[i]), 0);
        }

        unordered_map<int, vector<pair<int, int>>> q;
        for (int i = 0; i < queries.size(); ++i) {
            q[m - queries[i][1]].emplace_back(queries[i][0], i);
        }
        vector<int> ans(queries.size());

        unordered_map<int, int> temp;
        for (int i = m - 1; i >= 0; --i) {
            sort(all(a[i]), [&](int x, int y) {
                if (nums[x][i] != nums[y][i]) return nums[x][i] < nums[y][i];
                return a[i + 1][x] < a[i + 1][y];
            });
            //最右i位 排名为[j]是x
            if (q.count(i)) {
                for (auto& it : q[i]) {
                    ans[it.second] = a[i][it.first - 1];
                }
            }
            for (int j = 0; j < n; ++j) {
                temp[a[i][j]] = j;
            }
            for (int j = 0; j < n; ++j) {
                a[i][j] = temp[j];
            }
        }
        return ans;
    }
};
int main() {
    vector<string> a{"102", "473", "251", "814"};
    vector<vector<int>> q{{1, 1}};
    Solution().smallestTrimmedNumbers(a, q);
    return 0;
}