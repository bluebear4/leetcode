#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        vector<int> a, b;
        vector<int> c, d;

        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] & 1) {
                a.emplace_back(nums[i]);
            } else {
                c.emplace_back(nums[i]);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (target[i] & 1) {
                b.emplace_back(nums[i]);
            } else {
                d.emplace_back(nums[i]);
            }
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());
        sort(d.begin(), d.end());

        assert(a.size() == b.size());

        long long ans = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] < b[i]) {
                ans += (b[i] - a[i]) / 2;
            }
        }

        for (int i = 0; i < c.size(); ++i) {
            if (c[i] < d[i]) {
                ans += (c[i] - d[i]) / 2;
            }
        }

        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}