#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int minimizeXor(int num1, int num2) {
        int cnt1 = __builtin_popcount(num1);
        int cnt2 = __builtin_popcount(num2);
        if (cnt2 <= cnt1) {
            int ans = 0;
            for (int i = 30; i >= 0 && cnt2; --i) {
                if (num1 & (1 << i)) {
                    ans |= (1 << i);
                    --cnt2;
                }
            }
            return ans;
        }
        // cnt2>cnt1
        cnt2 -= cnt1;
        int ans = num1;
        for (int i = 0; i < 31 && cnt2; ++i) {
            if (!(ans & (1 << i))) {
                --cnt2;
                ans |= (1 << i);
            }
        }
        return ans;
    }
};
int main() {
    Solution().minimizeXor(25,72);
    return 0;
}