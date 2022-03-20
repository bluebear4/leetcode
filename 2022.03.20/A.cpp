#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int countHillValley(vector<int>& nums) {
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int n = nums.size(), ans = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (nums[i - 1] < nums[i] && nums[i] > nums[i + 1]) ++ans;
            if (nums[i - 1] > nums[i] && nums[i] < nums[i + 1]) ++ans;
        }
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}