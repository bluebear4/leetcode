#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define rall(x) x.rbegin(), x.rend()
class Solution {
#define all(x) x.begin(), x.end()
   public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
        sort(all(potions));
        transform(all(spells), spells.begin(), [&](int x) {
            double key = success * 1.0 / x;
            return potions.end() - lower_bound(all(potions), key);
        });
        return spells;
    }
};
int main() {
    // Solution()
    return 0;
}