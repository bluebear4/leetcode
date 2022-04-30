#include <bits/stdc++.h>
using namespace std;
#define rall(x) x.rbegin(), x.rend()
class Solution {
    using ll = long long;
#define all(x) x.begin(), x.end()

   public:
    ll maximumBeauty(vector<int>& f, ll newfs, int target, int good, int bad) {
        sort(all(f));
        ll L = 0;
        while (f.size() && f.back() >= target) {
            L += good;
            f.pop_back();
        }
        reverse(all(f));

        ll l = 0, n = f.size(), r = f.size() - 1, now = f.back();
        while (l < n) {
            if (newfs >= target - f[l]) {
                newfs -= target - f[l];
                L += good;
                ++l;
            } else {
                break;
            }
        }
        ll ans = L, maxx = 0;
        for (l; l >= 0; --l) {
            while (l <= r) {
                if (newfs >= 1ll * (n - r - 1) * (f[r] - now)) {
                    newfs -= 1ll * (n - r - 1) * (f[r] - now);
                    now = f[r];
                    if (l == r) maxx = max(maxx, newfs / (n - r) + now);
                    --r;
                } else {
                    maxx = max(maxx, newfs / (n - r - 1) + now);
                    break;
                }
            }
            ans = max(ans, L + maxx * bad);
            if (l < n) {
                newfs += target - f[l];
                L -= good;
            }
        }
        return ans;
    }
};
int main() {
    vector<int> a{2, 4, 5, 3};
    Solution().maximumBeauty(a, 10, 5, 2, 6);
    return 0;
}