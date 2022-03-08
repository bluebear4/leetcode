#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    using ll = long long;
    long long minimalKSum(vector<int>& nums, int k) {
        ll ans = 0;
        int last = 0;
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        for (auto& it : nums) {
            if (it - 1 - last <= k) {
                k -= it - 1 - last;
                ans += 1ll * (last + it) * (it - 1 - last) / 2;
                last = it;
            } else {
                it = last + k + 1;
                k = 0;
                ans += 1ll * (last + it) * (it - 1 - last) / 2;
                break;
            }
        }
        int it = last + k + 1;
        ans += 1ll * (last + it) * (it - 1 - last) / 2;
        return ans;
    }
};
int main() {
    vector<int> a{1, 4, 25, 10, 25};
    Solution().minimalKSum(a, 2);
    return 0;
}