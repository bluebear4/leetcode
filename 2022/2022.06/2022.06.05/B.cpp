#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rall(x) x.rbegin(), x.rend()
class Solution {
#define all(x) x.begin(), x.end()
   public:
    int partitionArray(vector<int>& nums, int k) {
        sort(all(nums));
        int n = nums.size();
        int ans = 1;
        for (int i = 0, now = nums[0]; i < n; ++i) {
            if (nums[i] - now > k) {
                ++ans;
                now = nums[i];
            }
        }
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}