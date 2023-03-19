#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0, j = 0; j < nums.size(); ++j) {
            if (nums[j] > nums[i]) {
                ++i;
                ++ans;
            }
        }
        return ans;
    }
};
// 8 13 21 21 28 35 42
// 13 21 21 28 35 42 8
int main() { return 0; }