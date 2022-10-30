#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        // 0 2 4 6 9
        // 2 0 1 4 3
        int n = nums.size();
        vector<int> ids(n);
        iota(ids.begin(), ids.end(), 0);
        sort(ids.begin(), ids.end(), [&nums](int x, int y) {
            if (nums[x] != nums[y]) return nums[x] > nums[y];
            return x > y;
        });

        set<int> now;
        vector<int> ans(n);
        for (auto& id : ids) {
            auto pos = now.upper_bound(id);
            if (pos == now.end()) {
                ans[id] = -1;
            } else {
                ++pos;
                if (pos == now.end()) {
                    ans[id] = -1;
                } else {
                    ans[id] = nums[*pos];
                }
            }
            now.insert(id);
        }
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}