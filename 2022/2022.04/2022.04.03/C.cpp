#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
using ll = long long;
   public:
    int maximumCandies(vector<int>& candies, long long k) {
        ll l = 0, r = 1e5 + 5, mid, ans = 0;
        auto check = [&](int x) {
            if (x == 0) return true;
            ll cnt = 0;
            for (auto it : candies) {
                cnt += it / x;
            }
            return cnt >= k;
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
    // Solution()
    return 0;
}