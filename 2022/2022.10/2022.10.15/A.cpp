#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
    bool check(const string &t) {
        int h = stoi(t.substr(0, 2));
        int m = stoi(t.substr(3));
        return h <= 23 && m <= 59;
    }

    int dfs(string &t, int pos) {
        if (pos == t.length()) return check(t);
        if (t[pos] != '?' || t[pos] == ':') return dfs(t, pos + 1);
        int ans = 0;
        for (int i = '0'; i <= '9'; ++i) {
            t[pos] = i;
            ans += dfs(t, pos + 1);
            t[pos] = '?';
        }
        return ans;
    }

   public:
    int countTime(string time) { return dfs(time, 0); }
};
int main() {
    // Solution()
    return 0;
}