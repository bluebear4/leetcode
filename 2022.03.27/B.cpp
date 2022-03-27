#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int minDeletion(vector<int>& nums) {
        map<int, unordered_set<int>> dp;
        dp[0].insert(-1);
        int maxx = 0;
        for (auto& num : nums) {
            if (maxx & 1) {
                if (dp.count(maxx - 1)) {
                    dp[maxx].insert(num);
                }
                if (dp[maxx].size() > 1 ||
                    (dp[maxx].size() == 1 && *dp[maxx].begin() != num)) {
                    maxx = maxx + 1;
                    dp[maxx].insert(num);
                }
            } else {
                if (dp.count(maxx - 1)) {
                    if (dp[maxx - 1].size() > 1 ||
                        (dp[maxx - 1].size() == 1 &&
                         *dp[maxx - 1].begin() != num)) {
                        dp[maxx].insert(num);
                    }
                }
                maxx = maxx + 1;
                dp[maxx].insert(num);
            }
        }
        if(maxx &1) --maxx;
        return nums.size() - maxx;
    }
};
int main() {
    vector<int> a{1, 1, 2, 2, 3, 3};
    Solution().minDeletion(a);
    return 0;
}