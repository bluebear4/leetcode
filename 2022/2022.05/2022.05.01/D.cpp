#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    long long appealSum(string s) {
        unordered_map<int, int> pos;
        long long ans = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (!pos.count(s[i])) pos[s[i]] = -1;
            ans += 1ll * (i - pos[s[i]]) * (n - i);
            pos[s[i]] = i;
        }
        return ans;
    }
};
int main() {
    Solution().appealSum("abbca");
    return 0;
}