#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int maxn = 3e5 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
    using ll = long long;

   public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if (finalSum & 1) return vector<long long>{};
        ll l = 0, r = INT_MAX, mid, cnt = 0;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (mid * 2 + mid * (mid + 1) < finalSum) {
                cnt = mid + 1;
                l = mid + 1;
            } else if (mid * 2 + mid * (mid + 1) == finalSum) {
                cnt = mid;
                break;
            } else {
                r = mid - 1;
            }
        }
        vector<long long> ans;
        for (int i = 0; i < cnt; ++i) {
            ans.emplace_back(2ll * i + 2);
            finalSum -= 2ll * i + 2;
        }
        ans.back() += finalSum;
        return ans;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    return 0;
}