#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
    using ll = long long;
    constexpr static int mod = 1e9 + 7;
    ll dfs(int startPos, int endPos, int k,
           vector<unordered_map<int, ll>> &dp) {
        if (abs(endPos - startPos) > k) return 0;
        if (abs(endPos - startPos) % 2 != k % 2) return 0;

        if (k == 0) return startPos == endPos;
        if (dp[k].count(startPos)) return dp[k][startPos];
        return dp[k][startPos] = (dfs(startPos + 1, endPos, k - 1, dp) +
                                  dfs(startPos - 1, endPos, k - 1, dp)) %
                                 mod;
    }

   public:
    int numberOfWays(int startPos, int endPos, int k) {
        vector<unordered_map<int, ll>> dp(k + 1, unordered_map<int, ll>{});
        return dfs(startPos, endPos, k, dp);
    }
};
int main() {
    // Solution()
    return 0;
}