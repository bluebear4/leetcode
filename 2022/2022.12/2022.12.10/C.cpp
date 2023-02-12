#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int maxJump(vector<int>& stones) {
        stones.emplace_back(1e9 + 5);
        auto check = [&stones](int x) {
            int n = stones.size();
            vector<int> vis(n);
            for (int i = 1, now = 0; i < n; ++i) {
                if (vis[i]) continue;
                if (abs(stones[i] - stones[now]) > x) {
                    vis[i - 1] = 1;
                    now = i - 1;
                }
            }
            for (int i = n - 3, now = n - 2; i >= 0; --i) {
                if (abs(stones[i] - stones[now]) <= x) {
                    if (vis[i] == 0) now = i;
                } else {
                    return false;
                }
            }
            return true;
        };
        int l = 0, r = 1e9 + 5, mid, ans = INT_MAX;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (check(mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
int main() {
    vector<int> a{0, 3};
    Solution().maxJump(a);
    return 0;
}