#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
class Solution {
    using ll = long long;
#define rall(x) x.rbegin(), x.rend()

   public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        auto dfs = [&](auto&& self, ll remain, bool first, ll k,
                       string& ans) -> void {
            if (remain <= 0) {
                if (k == 0) return;
                ans = "-1";
                return;
            }
            ll start = first, now = start, end = remain == 1;
            ll step = 1;
            for (int i = 1; i < remain; ++i) {
                step *= 10;
            }
            if (end) {
                while (k - (now - start + 1) * step >= 0 && now <= 9) {
                    now++;
                }
                now--;
                ans += '0' + now;
                self(self, remain - 1, false, k - (now - start + 1) * step,
                     ans);
            } else {
                while (k - (now - start) * step > 0 && now <= 9) {
                    now++;
                }
                now--;
                ans += '0' + now;
                self(self, remain - 1, false, k - (now - start) * step, ans);
            }
        };
        vector<ll> ans;
        for (auto& q : queries) {
            string s;
            dfs(dfs, (intLength + 1) / 2, true, q, s);
            if (s != "-1") {
                if (intLength & 1) {
                    string t = s.substr(0, s.length() - 1);
                    s += string(rall(t));
                } else {
                    s += string(rall(s));
                }
            }
            ans.emplace_back(stoll(s));
        }
        return ans;
    }
};
int main() {
    vector<int> a{10};
    Solution().kthPalindrome(a, 3);
    return 0;
}