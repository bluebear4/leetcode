#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
    using ll = long long;

   public:
    long long minimumDifference(vector<int>& nums) {
        ll l = 0;
        int n = nums.size() / 3;
        priority_queue<int> pq;
        map<int, ll> pos;
        for (int i = 0; i < 2 * n; ++i) {
            if (pq.size() < n) {
                l += nums[i];
                pq.push(nums[i]);
                if (pq.size() == n) {
                    pos[i] = l;
                }
            } else if (nums[i] < pq.top()) {
                l -= pq.top();
                pq.pop();
                l += nums[i];
                pq.push(nums[i]);
                pos[i] = l;
            }
        }
        ll ans = LONG_LONG_MAX, r = 0;
        auto now = pos.rbegin();
        priority_queue<int, vector<int>, greater<int>> bpq;
        for (int i = 3 * n - 1; i >= n; --i) {
            if (bpq.size() < n) {
                r += nums[i];
                bpq.push(nums[i]);
            } else if (nums[i] > bpq.top()) {
                r -= bpq.top();
                bpq.pop();
                r += nums[i];
                bpq.push(nums[i]);
            }
            if (bpq.size() == n) {
                while (now->first >= i) ++now;
                if (now == pos.rend()) return ans;
                ans = min(ans, now->second - r);
            }
        }
        return ans;
    }
};
int main() {
    vector<int> a{16, 46, 43, 41, 42, 14, 36, 49, 50, 28, 38,
                  25, 17, 5,  18, 11, 14, 21, 23, 39, 23};
    Solution().minimumDifference(a);
    return 0;
}