#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int minimumRecolors(string blocks, int k) {
        int ans = k;
        for (int i = 0; i + k <= blocks.length(); ++i) {
            ans = min<int>(ans, k - count(blocks.begin() + i,
                                          blocks.begin() + i + k, 'B'));
        }
        return ans <= 0 ? 0 : ans;
    }
};
int main() {
    // Solution()
    return 0;
}