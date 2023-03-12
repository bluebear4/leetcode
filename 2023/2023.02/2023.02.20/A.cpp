#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0, now = 0; i < n; ++i) {
            sum -= nums[i];
            ans[i] = abs(sum - now);
            now += nums[i];
        }
        return ans;
    }
};
int main() { return 0; }