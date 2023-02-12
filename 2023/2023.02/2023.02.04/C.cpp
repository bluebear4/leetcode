#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        int n = prizePositions.size();
        vector<int> dp(n + 1);
        {
            int pos = upper_bound(prizePositions.begin(), prizePositions.end(),
                                  prizePositions[0] + k) -
                      prizePositions.begin();
            for (int i = pos; i >= 0; --i) {
                dp[i] = i;
            }
        }
        for (int i = 0, maxx = 0; i < n; ++i) {
            int pos = upper_bound(prizePositions.begin(), prizePositions.end(),
                                  prizePositions[i] + k) -
                      prizePositions.begin();
            int cnt = pos - i;
            maxx = max(maxx, cnt);
            dp[pos] = maxx;
        }
        int ans = 0;
        for (int i = n - 1, maxx = 0; i >= 0; --i) {
            int pos = lower_bound(prizePositions.begin(), prizePositions.end(),
                                  prizePositions[i] - k) -
                      prizePositions.begin();
            int cnt = i - pos + 1;
            maxx = max(maxx, cnt);
            ans = max(ans, maxx + dp[pos]);
        }

        return ans;
    }
};
int main() { return 0; };
