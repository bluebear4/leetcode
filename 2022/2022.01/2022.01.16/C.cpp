#include <bits/stdc++.h>
using namespace std;
class Solution {
    using ll = long long;
    // 0 4 4 2 0
   public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<ll> dp(n + 1);
        for (int i = n - 1; i >= 0; --i) {
            if (i + questions[i][1] + 1 >= n) {
                dp[i] = max<ll>(dp[i + 1], questions[i][0]);
            } else {
                dp[i] = max<ll>(dp[i + 1],
                                dp[i + questions[i][1] + 1] + questions[i][0]);
            }
        }
        return dp[0];
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    return 0;
}