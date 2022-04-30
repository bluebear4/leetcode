#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    vector<int> intersection(vector<vector<int>>& nums) {
        sort(nums[0].begin(), nums[0].end());
        vector<int> ans(nums[0].begin(), nums[0].end());
        for (int i = 1; i < nums.size(); ++i) {
            sort(nums[i].begin(), nums[i].end());
            vector<int> t;
            set_intersection(ans.begin(), ans.end(), nums[i].begin(),
                             nums[i].end(), std::back_inserter(t));
            t.swap(ans);
        }
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}