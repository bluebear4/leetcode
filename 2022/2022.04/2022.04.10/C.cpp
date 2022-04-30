#include <bits/stdc++.h>
using namespace std;
#define rall(x) x.rbegin(), x.rend()
class Solution {
    using ll = long long;
    static constexpr ll mod = 1e9 + 7;
#define all(x) x.begin(), x.end()
   public:
    int maximumProduct(vector<int>& nums, int k) {
        multiset<int> mset(all(nums));
        while (k--) {
            int temp = *mset.begin();
            mset.erase(mset.begin());
            mset.insert(++temp);
        }
        ll ans = 1;
        for (auto& it : mset) {
            ans = ans * it % mod;
        }
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}