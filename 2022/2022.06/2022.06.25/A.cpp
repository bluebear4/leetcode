#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int countAsterisks(string s) {
        int pos = -1, ans = 0;
        while (1) {
            auto l = s.find('|', pos + 1);
            if (l == string::npos) break;
            auto r = s.find('|', l + 1);
            if (r == string::npos) break;
            ans += count(s.begin() + l, s.begin() + r, '*');
            pos = r;
        }
        return count(s.begin(), s.end(), '*') - ans;
    }
};
int main() {
    Solution().countAsterisks("***|");
    return 0;
}