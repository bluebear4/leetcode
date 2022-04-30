#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rall(x) x.rbegin(), x.rend()
class Solution {
#define all(x) x.begin(), x.end()
   public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2, vector<int>{});
        unordered_set<int> a(all(nums1)), b(all(nums2));
        for (auto& it : a) {
            if (!b.count(it)) {
                ans[0].emplace_back(it);
            }
        }
        for (auto& it : b) {
            if (!a.count(it)) {
                ans[1].emplace_back(it);
            }
        }
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}