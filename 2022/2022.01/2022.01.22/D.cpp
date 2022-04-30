#include <bits/stdc++.h>
using namespace std;
class Solution {
    using ll = long long;
    const ll mod = 1e9 + 7;

   public:
    int numberOfWays(string corridor) {
        int cnt = count(corridor.begin(), corridor.end(), 'S');
        if (cnt % 2 != 0 || cnt == 0) return 0;
        cnt>>=1;
        --cnt;
        ll ans = 1;
        int now = 0, i = 0;
        for (int i = 0, now = 0, last = 0; i < corridor.length(); ++i) {
            if (corridor[i] == 'S') {
                ++now;
                if (now == 2 && cnt) {
                    int j = i + 1;
                    while (j < corridor.length() && corridor[j] == 'P') ++j;
                    ans *= (j - i);
                    ans %= mod;
                    now = 0;
                    i = j - 1;
                    --cnt;
                }
            }
        }
        return ans;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    Solution().numberOfWays("SSSPPPSPPSPSSSSSSPPPSPP");
    return 0;
}