#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
    int dp[100][100];

    bool isprimer(int x) {
        return x == '2' || x == '3' || x == '5' || x == '7';
    }
    int dfs(const string& s, int l, int k, int minLength) {
        static constexpr int mod = 1e9 + 7;
        if (!isprimer(s[l])) return 0;
        if (k == 1) return s.length() - l >= minLength;
        if (dp[l][k] != -1) return dp[l][k];
        dp[l][k] = 0;
        for (int i = l + 1; i < s.length(); ++i) {
            if (i - l + 1 >= minLength && !isprimer(s[i])) {
                dp[l][k] += dfs(s, i + 1, k - 1, minLength);
                dp[l][k] %= mod;
            }
        }
        return dp[l][k];
    }

   public:
    int beautifulPartitions(string s, int k, int minLength) {
        // dp[i][j] = 到下标i为止 已经有j个
        if (!isprimer(s[0]) || isprimer(s.back())) return 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = -1;
            }
        }
        return dfs(s, 0, k, minLength);
    }
};
int main() {
    string s{"23542185131"};
    Solution().beautifulPartitions(s, 3, 2);
    return 0;
}