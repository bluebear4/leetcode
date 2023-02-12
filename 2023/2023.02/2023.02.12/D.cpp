#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int minimumScore(string s, string t) {
        vector<vector<int>> pos(26);
        for (int i = 0; i < s.length(); ++i) {
            pos[s[i] - 'a'].emplace_back(i);
        }
        vector<int> a(t.length(), -1);
        for (int i = t.length() - 1, now = s.length(); i >= 0; --i) {
            int ch = t[i] - 'a';
            auto it = upper_bound(pos[ch].rbegin(), pos[ch].rend(), now,
                                  greater<int>());
            if (it == pos[ch].rend()) break;
            now = a[i] = *it;
        }
        int ans = t.length();
        for (int i = 0, l = -1; i < t.length(); ++i) {
            // 从i开始删 末尾有几个能不删
            int cnt = a.end() - upper_bound(a.begin(), a.end(), l);
            ans = min<int>(ans, t.length() - i - cnt);
            if (ans == 0) break;
            // i不删
            int ch = t[i] - 'a';
            auto it = upper_bound(pos[ch].begin(), pos[ch].end(), l);
            if (it == pos[ch].end()) break;
            l = *it;
        }
        return ans;
    }
};
int main() {
    Solution().minimumScore("adebddaccdcabaade", "adbae");
    return 0;
}