#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());

        int l = 0, r = price.back() - price[0], mid, ans = 0;
        int n = price.size();
        auto check = [&price, &n, &k](int x) -> bool {
            for (int need = 0, cnt = 0; cnt < k; need += x, ++cnt) {
                auto pos = lower_bound(price.begin(), price.end(), need);
                if (pos == price.end()) return cnt >= k;
                need = *pos;
            }
            return true;
        };
        while (l <= r) {
            mid = (l + r) >> 1;
            if (check(mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
int main() {
    vector<int> a{34, 116, 83, 15, 150, 56, 69, 42, 26};
    Solution().maximumTastiness(a, 6);
    return 0;
}