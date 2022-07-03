#include <bits/stdc++.h>
using namespace std;
#define rall(x) x.rbegin(), x.rend()
class Solution {
    using ll = long long;
#define all(x) x.begin(), x.end()
   public:
    int waysToSplitArray(vector<int>& nums) {
        ll right = accumulate(all(nums), 0ll), left = 0;
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n - 1; ++i) {
            left += nums[i];
            right -= nums[i];
            ans += left >= right;
        }
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}