#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int longestNiceSubarray(vector<int>& nums) {
        int l = 0, r = 0, ans = 0;
        vector<int> now(64);
        while (r < nums.size()) {
            bool ok = true;
            for (int i = 0; i <= 31; ++i) {
                if (nums[r] >> i & 1) {
                    if (++now[i] > 1) {
                        ok = false;
                    }
                }
            }
            ++r;

            while (!ok) {
                ok = true;
                for (int i = 0; i <= 31; ++i) {
                    if (nums[l] >> i & 1) {
                        if (--now[i] > 1) {
                            ok = false;
                        }
                    }
                }
                ++l;
            }
            ans = max(ans, r - l);
        }
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}