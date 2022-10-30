#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
    long long get_cost(vector<int>& nums, vector<int>& cost, int x) {
        long long ret = 0;
        for (int i = 0; i < nums.size(); ++i) {
            ret += 1ll * abs(nums[i] - x) * cost[i];
        }
        return ret;
    }

    bool is_up(vector<int>& nums, vector<int>& cost, int x, int y) {
        return get_cost(nums, cost, x) < get_cost(nums, cost, y);
    }

   public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        auto pos = minmax_element(nums.begin(), nums.end());
        int l = *pos.first, r = *pos.second, mid;
        long long ans = LONG_LONG_MAX;
        while (l <= r) {
            mid = (l + r) >> 1;
            ans = min(ans, get_cost(nums, cost, mid));
            if (is_up(nums, cost, mid, mid + 1)) {
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