#include <bits/stdc++.h>
using namespace std;
#define rall(x) x.rbegin(), x.rend()
class Solution {
    using ll = long long;
#define all(x) x.begin(), x.end()
    struct node {
        ll x, y, val;
        bool operator<(const node& r) const { return val > r.val; }
        node(ll a, ll b) : x(a), y(b), val(abs(a - b)) {}
    };

   public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1,
                               int k2) {
        int n = nums1.size();
        int k = k1 + k2;
        vector<node> a;
        for (int i = 0; i < n; ++i) {
            a.emplace_back(nums1[i], nums2[i]);
        }
        sort(all(a));
        for (int i = 0, cnt = 1; i + 1 < n; ++i) {
            ll diff = a[i].val - a[i + 1].val;
            if (k >= diff * cnt) {
                k -= diff * cnt;
                ++cnt;
            } else {
                ll ans = (a[i].val - k / cnt) * (a[i].val - k / cnt) *
                             (cnt - k % cnt) +
                         (a[i].val - k / cnt - 1) * (a[i].val - k / cnt - 1) *
                             (k % cnt);
                while (++i < n) {
                    ans += a[i].val * a[i].val;
                }
                return ans;
            }
        }
        if (k <= a.back().val * n) {
            return (a.back().val - k / n) * (a.back().val - k / n) *
                       (n - k % n) +
                   (a.back().val - k / n - 1) * (a.back().val - k / n - 1) *
                       (k % n);
        }
        return 0;
    }
};
int main() {
    vector<int> a{10, 10, 10, 11, 5};
    vector<int> b{1, 0, 6, 6, 1};
    Solution().minSumSquareDiff(a, b, 11, 27);
    return 0;
}