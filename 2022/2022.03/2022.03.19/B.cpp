#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
    using ll = long long;
    ll getans(const string &s, const string &a_b) {
        vector<int> pos_a, pos_b;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == a_b[0]) pos_a.push_back(i);
            if (s[i] == a_b[1]) pos_b.push_back(i);
        }
        ll ans = 0;
        for (auto &it : pos_a) {
            ans += pos_b.end() - upper_bound(pos_b.begin(), pos_b.end(), it);
        }
        return ans;
    }

   public:
    long long maximumSubsequenceCount(string text, string pattern) {
        return max(getans(pattern[0] + text, pattern),
                   getans(text + pattern[1], pattern));
    }
};
int main() {
    // Solution()
    return 0;
}