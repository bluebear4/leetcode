#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int giveGem(vector<int>& gem, vector<vector<int>>& operations) {
        for (auto& op : operations) {
            int num = gem[op[0]] / 2;
            gem[op[0]] -= num;
            gem[op[1]] += num;
        }
        return *max_element(gem.begin(), gem.end()) -
               *min_element(gem.begin(), gem.end());
    }
};
int main() {
    // Solution()
    return 0;
}