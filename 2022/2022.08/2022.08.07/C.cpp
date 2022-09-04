#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    bool validPartition(vector<int>& nums) {
        // dp[i][j] 表示到i能否划分，j是相同还是上升
        int n = nums.size();
        vector<int> dp(n);
        for (int i = 1; i < n; ++i) {
            if (i - 2 == -1 || dp[i - 2]) {
                if (nums[i - 1] == nums[i]) dp[i] = 1;
            }
            if (i >= 2 && (i - 3 == -1 || dp[i - 3])) {
                if (nums[i - 1] == nums[i] && nums[i - 2] == nums[i - 1]) {
                    dp[i] = 1;
                }
                if (nums[i - 1] + 1 == nums[i] &&
                    nums[i - 2] + 1 == nums[i - 1]) {
                    dp[i] = 1;
                }
            }
        }
        return dp.back();
    }
};
int main() {
    vector<int> a{1, 1, 1, 1, 2, 3};
    Solution().validPartition(a);
    return 0;
}