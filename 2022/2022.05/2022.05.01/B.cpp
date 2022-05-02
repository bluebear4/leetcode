#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < cards.size(); ++i) {
            pos[cards[i]].emplace_back(i);
        }
        int ans = INT_MAX;
        for (auto& [k, v] : pos) {
            for (int i = 1; i < v.size(); ++i) {
                ans = min(ans, v[i] - v[i - 1] + 1);
            }
        }
        if (ans == INT_MAX) return -1;
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}