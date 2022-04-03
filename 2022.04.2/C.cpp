#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    long long numberOfWays(string s) {
        // 010 101
        int rzero = count(s.begin(), s.end(), '0');
        int rone = count(s.begin(), s.end(), '1');
        int lzero = 0, lone = 0;
        long long sum = 0;
        for (auto &it : s) {
            rzero -= (it == '0');
            rone -= (it == '1');
            lzero += (it == '0');
            lone += (it == '1');
            if (it == '0') {
                sum += 1ll * lone * rone;
            } else {
                sum += 1ll * lzero * rzero;
            }
        }
        return sum
    }
};
int main() {
    // Solution()
    return 0;
}