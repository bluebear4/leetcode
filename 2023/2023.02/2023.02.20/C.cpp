#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
         sort(nums.begin(), nums.end());
        int n = nums.size();

        int ans = 0;
        while (a.size() > 1) {
            int r = *a.rbegin();
            auto it = a.upper_bound(r / 2);
            if (it == a.begin()) return ans;
            ans += 2;
            a.erase(--it);
            a.erase(--a.end());
        }
        return ans;
    }
};
int main() {
    vector<int> a{9,  10, 10, 14, 15, 16, 17, 17, 24, 28, 29, 31, 32,
                  40, 42, 48, 51, 55, 64, 68, 71, 83, 98, 99, 99, 100};
    Solution().maxNumOfMarkedIndices(a);
    return 0;
};
