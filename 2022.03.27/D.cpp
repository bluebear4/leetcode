#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rall(x) x.rbegin(), x.rend()
class Solution {
#define all(x) x.begin(), x.end()

   public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<int> dp(k + 1);
        //用了i次的最值
        vector<vector<int>> sum(all(piles));
        for (auto& vec : sum) {
            for (int i = 1; i < vec.size(); ++i) {
                vec[i] += vec[i - 1];
            }
            vec.insert(vec.begin(), 0);
        }
        int ans = 0;
        int n = piles.size();
        for (int i = 0; i < n; ++i) {
            for (int j = k; j >= 0; --j) {
                for (int l = 0; l < sum[i].size() && l <= j; ++l) {
                    dp[j] = max(dp[j], dp[j - l] + sum[i][l]);
                    ans = max(ans, dp[j]);
                }
            }
        }
        return ans;
    }
};
int main() {
    vector<vector<int>> a{
        {100}, {100}, {100}, {100}, {100}, {100}, {1, 1, 1, 1, 1, 1, 700}};
    Solution().maxValueOfCoins(a, 7);
    return 0;
}