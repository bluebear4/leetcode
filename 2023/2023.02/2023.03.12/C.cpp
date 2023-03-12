#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    long long beautifulSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> cnt;
        for (int i = 0, now = 0; i < n; ++i) {
            cnt[now ^= nums[i]]++;
        }
        long long ans = count(nums.begin(), nums.end(), 0);
        for (int i = 0, now = 0; i < n; ++i) {
            now ^= nums[i];
            --cnt[now];
            ans += cnt[now ^ nums[i]];
        }
        return ans;
    }
};
// 4 7 6 4 0
// a ab abc abcd abcde
int main() {
    vector<int> a{4, 3, 1, 2, 4};
    Solution().beautifulSubarrays(a);
    return 0;
};
