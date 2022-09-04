#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
class Solution {
#define rall(x) x.rbegin(), x.rend()
   public:
    string largestPalindromic(string num) {
        vector<int> cnt(10);
        for (auto &it : num) cnt[it - '0']++;
        string ans;
        for (int i = 9; i >= 0; --i) {
            if (i == 0 && ans.empty()) continue;
            ans += string(cnt[i] / 2, '0' + i);
            cnt[i] -= cnt[i] / 2 * 2;
        }
        for (int i = 9; i >= 0; --i) {
            if (cnt[i]) {
                return ans + string(1, '0' + i) + string(rall(ans));
            }
        }
        return ans + string(rall(ans));
    }
};
int main() {
    // Solution()
    return 0;
}