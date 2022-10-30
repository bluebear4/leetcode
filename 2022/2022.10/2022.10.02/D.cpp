#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
    struct str_hash {
        using ull = unsigned long long;
        const ull hash1 = 1610612741;
        string str;
        vector<ull> pp, ha;
        int len;

        str_hash(const string &str) {
            len = str.size();
            this->str = str;

            pp.resize(len + 1);
            pp[0] = 1;
            for (int i = 1; i <= len; ++i) pp[i] = hash1 * pp[i - 1];

            ha.resize(len + 1);
            for (int i = 1; i <= len; ++i)
                ha[i] = ha[i - 1] * hash1 + str[i - 1];
        }
        //求str[l,r]的哈希值，整个串为str[1,len]
        ull get_hash(int l, int r) { return ha[r] - ha[l - 1] * pp[r - l + 1]; }
    };

   public:
    int deleteString(string s) {
        int n = s.length();
        // dp[i] = 删除了前i个的最大操作
        vector<int> dp(n + 1, -1e9);
        dp[0] = 0;

        // i 删除了i个
        str_hash hs(s);

        for (int i = 0; i < s.length(); ++i) {
            for (int j = i + 2; j <= s.length(); j += 2) {
                int len = j - i;
                if (hs.get_hash(i + 1, i + len / 2) ==
                    hs.get_hash(i + 1 + len / 2, j))
                // string l = s.substr(i, len / 2);
                // string r = s.substr(i + len / 2, len / 2);
                // if (l == r)
                {
                    dp[i + len / 2] = max(dp[i + len / 2], dp[i] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end()) + 1;
    }
};
int main() {
    Solution().deleteString("aaaaa");
    return 0;
}