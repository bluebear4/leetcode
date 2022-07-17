#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rall(x) x.rbegin(), x.rend()
class Solution {
#define all(x) x.begin(), x.end()
    bool maxSlidingWindow(vector<double>& nums, int k) {
        int n = nums.size();
        deque<double> q;
        for (int i = 0; i < k; ++i) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }

        double ans = nums[q.front()];
        if (ans < k) return true;
        for (int i = k; i < n; ++i) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
            while (q.front() <= i - k) {
                q.pop_front();
            }
            if (nums[q.front()] < k) return true;
        }
        return false;
    }

   public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        srand(time(0));
        int n = nums.size();
        vector<double> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = threshold * 1.0 / nums[i];
        }
        vector<int> b(n);
        vector<double> c(a);
        sort(all(c));
        iota(all(b), 1);
        unordered_map<int, int> cnt;
        for (int i = 1; i <= n; ++i) {
            auto it = lower_bound(all(c), i);
            cnt[i] = it - c.begin();
        }
        sort(all(b), [&](int x, int y) { return cnt[x] > cnt[y]; });
        for (auto& k : b) {
            if (cnt[k] < k) continue;
            if (maxSlidingWindow(a, k)) return k;
        }
        return -1;
    }
    // 6 2 1.5 2 6
    // 1.16 1.4 1.16 1.4 0.875
    // k>threshold/a[i]
};
int main() {
    vector<int> a{1, 3, 4, 3, 1};
    Solution().validSubarraySize(a, 6);
    return 0;
}