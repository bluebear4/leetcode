#include <bits/stdc++.h>
using namespace std;
#define rall(x) x.rbegin(), x.rend()
class Solution {
    using ll = long long;
    using pll = pair<ll, ll>;
#define all(x) x.begin(), x.end()
   public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        if (stockPrices.size() == 1) return 0;
        sort(all(stockPrices));
        vector<pll> ans;
        for (int i = 1; i < stockPrices.size(); ++i) {
            ans.emplace_back(stockPrices[i][1] - stockPrices[i - 1][1],
                             stockPrices[i][0] - stockPrices[i - 1][0]);
        }
        return unique(all(ans),
                      [](pll& x, pll& y) {
                          return x.first * y.second == x.second * y.first;
                      }) -
               ans.begin();
    }
};
int main() {
    // Solution()
    return 0;
}