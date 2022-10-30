#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
    using ll = long long;
    bool check(vector<int> n, int x) {
        vector<ll> nums(n.begin(), n.end());
        while (nums.size() > 1) {
            if (nums.back() > x) {
                nums[nums.size() - 2] += nums.back() - x;
            }
            nums.pop_back();
        }
        return nums.back() <= x;
    }

   public:
    int minimizeArrayValue(vector<int>& nums) {
        int l = 0, r = 1e9, mid, ans;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(nums, mid)) {
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
    // Solution()
    return 0;
}