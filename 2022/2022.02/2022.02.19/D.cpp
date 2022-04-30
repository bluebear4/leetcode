#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/trie_policy.hpp>
using namespace __gnu_pbds;
class Solution {
    using ll = long long;

   public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hs;
        int now = 0;
        for (auto& it : nums1) {
            hs[it] = now++;
        }
        for (auto& it : nums2) {
            it = hs[it];
        }
        tree<ll, null_type, less<ll>, rb_tree_tag,
             tree_order_statistics_node_update>
            l, r;
        int n = nums2.size();
        for (int i = n - 1; i >= 0; --i) {
            r.insert(nums2[i]);
        }
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            r.erase(nums2[i]);
            ll L = l.order_of_key(nums2[i]);
            ll R = r.order_of_key(nums2[i]);
            ans += L * (r.size() - R);
            l.insert(nums2[i]);
        }
        // 0 2 1 4 3
        return ans;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    vector<int> a{2, 0, 1, 3};
    vector<int> b{0, 1, 2, 3};
    Solution().goodTriplets(a, b);
    return 0;
}