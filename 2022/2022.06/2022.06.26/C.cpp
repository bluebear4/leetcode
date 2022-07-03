#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rall(x) x.rbegin(), x.rend()
class Solution {
#define all(x) x.begin(), x.end()
   public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2,
                             bool swap = true) {
        // 50 -30 50
        //-30 20 -30 30 10
        int n = nums1.size();
        vector<int> nums3(all(nums1));
        for (int i = 0; i < n; ++i) {
            nums3[i] -= nums2[i];
        }

        int l = -1, r = -1;
        for (int i = 0, sum = 0, maxx = 0, L = -1, now = 0; i < n; ++i) {
            sum += nums3[i];
            if (sum > maxx) {
                L = i;
                maxx = sum;
            }
            if (sum - maxx < now) {
                now = sum - maxx;
                r = i + 1;
                l = L;
            }
        }
        int ans = accumulate(nums1.begin(), nums1.end(), 0);
        if (l < r)
            ans += accumulate(nums2.begin() + l + 1, nums2.begin() + r, 0) -
                   accumulate(nums1.begin() + l + 1, nums1.begin() + r, 0);
        if (swap) return max(ans, maximumsSplicedArray(nums2, nums1, false));
        return ans;
    }
};
int main() {
    vector<int> a{10};
    vector<int> b{10};
    Solution().maximumsSplicedArray(a, b);
    return 0;
}