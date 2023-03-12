#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        // 改最小的两个
        int ans = nums.back() - nums[2];
        // 改最大的两个
        ans = min(ans, nums[n - 1 - 2] - nums[0]);
        // 改一大一小
        nums[0] = nums[1];
        nums[n - 1] = nums[n - 2];
        int mini = INT_MAX;
        for (int i = 0; i + 1 < n; ++i) {
            mini = min(mini, nums[i + 1] - nums[i]);
        }
        ans = min(ans, mini + nums.back() - nums[0]);
        return ans;
    }
};
int main() { return 0; }