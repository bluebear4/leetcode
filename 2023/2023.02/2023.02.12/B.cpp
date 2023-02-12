#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag,
                              tree_order_statistics_node_update>;
class Solution {
   public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        ordered_multiset<int> T;
        long long ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int l = lower - nums[i], r = upper - nums[i];
            int R = T.order_of_key(r+1);
            int L = T.order_of_key(l);
            ans += R - L;
            T.insert(nums[i]);
        }
        return ans;
    }
};
int main() {
    vector<int> a{0, 1, 7, 4, 4, 5};
    Solution().countFairPairs(a, 3, 6);
    ordered_multiset<int> T;
    T.insert(1);
    T.insert(1);
    cout << T.order_of_key(1);
    return 0;
}