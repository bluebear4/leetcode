#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<int> pos(32, -1);
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            for (int j = 0; j < 31; ++j) {
                if (num >> j & 1) {
                    pos[j] = i;
                }
            }
        }

        vector<int> cnt(32);
        vector<int> ans(nums.size());
        for (int l = 0, r = 0; l < nums.size();) {
            int ok = true;
            for (int j = 0; j < 31; ++j) {
                if (cnt[j] == 0 && pos[j] >= l) {
                    ok = false;
                }
            }
            if (ok) {
                ans[l] = max(1, r - l);
                for (int j = 0; j < 31; ++j) {
                    if (nums[l] >> j & 1) {
                        cnt[j]--;
                    }
                }
                ++l;
            } else {
                for (int j = 0; j < 31; ++j) {
                    if (nums[r] >> j & 1) {
                        cnt[j]++;
                    }
                }
                ++r;
            }
        }
        return ans;
    }
};
int main() {
    vector<int> a{0};
    Solution().smallestSubarrays(a);
    return 0;
}