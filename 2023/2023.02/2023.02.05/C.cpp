#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int minCapability(vector<int>& nums, int k) {
        auto check = [&nums, k](int x) {
            int y = k;
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] <= x) {
                    ++i;
                    --y;
                }
            }
            return y <= 0;
        };
        int l = 0, r = 1e9, mid, ans;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (check(mid)) {
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
    vector<int> a{2, 7, 9, 3, 1};
    Solution().minCapability(a, 2);
    return 0;
};
