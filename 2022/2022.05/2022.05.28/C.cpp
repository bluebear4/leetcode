#include <bits/stdc++.h>
using namespace std;
#define rall(x) x.rbegin(), x.rend()
class Solution {
#define all(x) x.begin(), x.end()
    using ll = long long;

   public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> in(n);
        for (auto& road : roads) {
            ++in[road[0]];
            ++in[road[1]];
        }
        ll ans = 0, now = n;
        sort(all(in), greater<int>());
        for (auto& it : in) {
            ans += it * now--;
        }
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}