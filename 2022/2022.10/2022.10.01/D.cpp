#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/trie_policy.hpp>
using namespace __gnu_pbds;

class Solution {
   public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        long long ans = 0;
        using ll = long long;
        using pll = pair<ll, ll>;

        gp_hash_table<ll, ll> H;
        tree<pll, null_type, less<pll>, rb_tree_tag,
             tree_order_statistics_node_update>
            T;
        for (int i = 0; i < n; ++i) {
            T.insert(pll(nums1[i] - nums2[i], ++H[nums1[i] - nums2[i]]));
        }

        for (int i = 0; i < n; ++i) {
            T.erase(pll(nums1[i] - nums2[i], H[nums1[i] - nums2[i]]--));
            ans +=
                T.size() - T.order_of_key(pll(nums1[i] - nums2[i] - diff, -1));
        }
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}