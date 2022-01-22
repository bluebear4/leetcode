#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int ans = 0;
        while (cost.size()) {
            ans += cost.back();
            cost.pop_back();
            if (cost.empty()) return ans;
            ans += cost.back();
            cost.pop_back();
            if (cost.empty()) return ans;
            cost.pop_back();
        }
        return ans;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    return 0;
}