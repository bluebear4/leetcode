#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
    using ll = long long;

   public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int i = 0, j = 0;
        ll now = 0, ans = 0;
        // 2 1 4 3 5
        while (i < nums.size()) {
            while (j < nums.size() && (now + nums[j]) * (j - i + 1) < k) {
                now += nums[j++];
            }
            ans += j - i;
            now -= nums[i++];
            while (j < i) now += nums[j++];
        }
        return ans;
    }
};
int main() {
    vector<int> a{2, 1, 4, 3, 5};
    Solution().countSubarrays(a, 1);
    return 0;
}