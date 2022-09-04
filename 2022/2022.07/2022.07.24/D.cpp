#include <bits/stdc++.h>
using namespace std;
class Solution {
#define all(x) x.begin(), x.end()
   public:
    long long countExcellentPairs(vector<int>& fks, int k) {
        unordered_set<int> nums(all(fks));
        vector<int> cnt;
        for (auto& num : nums) {
            cnt.emplace_back(__builtin_popcount(num));
        }
        sort(all(cnt));
        long long ans = 0;
        for (auto& it : cnt) {
            ans += cnt.end() - lower_bound(all(cnt), k - it);
        }
        return ans;
    }
};
int main() { return 0; }