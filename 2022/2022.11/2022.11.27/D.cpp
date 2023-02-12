#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int countSubarrays(vector<int>& nums, int k) {
        int pos = find(nums.begin(), nums.end(), k) - nums.begin();
        unordered_map<int, int> big;
        for (int i = pos, cnt = 0; i < nums.size(); ++i) {
            if (nums[i] > k) ++cnt;
            if (nums[i] < k) --cnt;
            big[cnt]++;
        }
        int ans = 0;
        for (int i = pos, cnt = 0; i >= 0; --i) {
            if (nums[i] < k) ++cnt;
            if (nums[i] > k) --cnt;
            // big == small || big==small+1
            ans += big[cnt] + big[cnt + 1];
        }
        return ans;
    }
};
int main() {
    vector<int> a{3, 2, 1, 4, 5};
    Solution().countSubarrays(a, 4);
    return 0;
}