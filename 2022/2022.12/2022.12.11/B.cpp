#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int> vis(nums.begin(), nums.end());
        int ans = -1;
        for (int i = 2; i * i <= 100000; ++i) {
            if (!vis.count(i) || !vis.count(i * i)) continue;
            int now = 2;
            for (long long j = i * i * i * i; j <= 100000; j *= j) {
                if (!vis.count(j)) break;
                ++now;
            }
            ans = max<int>(ans, now);
        }
        return ans;
    }
};
int main() {
    vector<int> a{3, 9, 81, 6561};
    Solution().longestSquareStreak(a);
    return 0;
}