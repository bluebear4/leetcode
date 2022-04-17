#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
    using ll = long long;

   public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        ll ans = 0;
        for (int i = 0; i * cost1 <= total; ++i) {
            int remain = total - i * cost1;
            ans += remain / cost2 + 1;
        }
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}