#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rall(x) x.rbegin(), x.rend()
class Solution {
#define all(x) x.begin(), x.end()
    bool check(long long x, vector<vector<int>>& kui, int cost) {
        for (auto& vec : kui) {
            if (x < vec[0]) return false;
            x += vec[1] - vec[0];
        }
        return x >= cost;
    }

   public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        // [5,0] [2,1] [4,2]
        vector<vector<int>> kui;
        int cost = 0;
        for (auto& vec : transactions) {
            if (vec[0] - vec[1] <= 0) {
                cost = max(cost,vec[0]);
                continue;
            }
            kui.emplace_back(vec);
        }
        sort(all(kui), [&](const vector<int>& l, const vector<int>& r) {
            if (l[1] != r[1]) return l[1] < r[1];
            return l[0] > r[0];
        });
        //亏 赚
        long long l = 0, r = 1e15, ans = 0;
        while (l <= r) {
            long long mid = (l + r) >> 1;
            if (check(mid, kui, cost)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
int main() {
    vector<vector<int>> a{{3, 9}, {0, 4}, {7, 10}, {3, 5}, {0, 9},
                          {9, 3}, {7, 4}, {0, 0},  {3, 3}, {8, 0}};
    Solution().minimumMoney(a);
    return 0;
}