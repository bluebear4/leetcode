#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rall(x) x.rbegin(), x.rend()
class Solution {
#define all(x) x.begin(), x.end()
   public:
    int longestIdealString(string s, int k) {
        int n = s.length();
        vector<int> dp(n, 1);
        vector<int> pos(26, -1);
        for (int i = 0; i < n; ++i) {
            int x = s[i] - 'a';
            for (int j = max(0, x - k); j <= min(x + k, 25); ++j) {
                if (pos[j] == -1) continue;
                dp[i] = max(dp[i], dp[pos[j]] + 1);
            }
            pos[x] = i;
        }
        return *max_element(all(dp));
    }
};
int main() {
    // Solution()
    return 0;
}