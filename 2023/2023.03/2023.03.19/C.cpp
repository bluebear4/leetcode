#include <bits/stdc++.h>
using namespace std;
class Solution {
    int dfs(const vector<int>& nums, int k, vector<int>& vis, int index) {
        if (index == nums.size()) return 1;
        int ans = 0;
        if (nums[index] < k || !vis[nums[index] - k]) {
            vis[nums[index]]++;
            ans += dfs(nums, k, vis, index + 1);
            vis[nums[index]]--;
        }
        return ans + dfs(nums, k, vis, index + 1);
    }

   public:
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<int> vis(1005);
        return dfs(nums, k, vis, 0) - 1;
    }
};
int main() {
    vector<int> a{10, 4, 5, 7, 2, 1};
    Solution().beautifulSubsets(a, 3);
    return 0;
};
