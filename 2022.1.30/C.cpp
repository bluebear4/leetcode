#include <bits/stdc++.h>
using namespace std;
//一开始以为是模板就直接套 发现哈希算法不一样 改了一下发现要除 但是不一定有逆元 思维江化卡住了
class Solution {
    using ll = long long;

   public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        int n = s.length();
        vector<ll> ha(n + 1);
        string ans;
        for (int i = n - 1; i >= n - k; --i) {
            ha[i] = (ha[i + 1] * power + (s[i] - 'a' + 1)) % modulo;
        }
        if (ha[n - k] == hashValue) {
            ans = s.substr(n - k, k);
        }
        ll pp = 1;
        for (int i = 0; i < k - 1; ++i) {
            pp = power * pp % modulo;
        }
        for (int i = n - k - 1; i >= 0; --i) {
            ha[i] = (ha[i + 1] - (s[i + k] - 'a' + 1) * pp % modulo) % modulo +
                    modulo;
            ha[i] %= modulo;
            ha[i] = (ha[i] * power + (s[i] - 'a' + 1)) % modulo;
            if (ha[i] == hashValue) {
                ans = s.substr(i, k);
            }
        }
        return ans;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    Solution().subStrHash("leetcode", 7, 20, 2, 0);
    return 0;
}