#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int minimumAverageDifference(vector<int>& nums) {
        long long pre = 0, suf = accumulate(nums.begin(), nums.end(), 0ll);
        int n = nums.size(), ans = INT_MAX, index = -1;
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            pre += num;
            suf -= num;
            if (n - i - 1 == 0) {
                if (ans > pre / (i + 1)) {
                    ans = pre / (i + 1);
                    index = i;
                }
            } else if (ans > abs(pre / (i + 1) - suf / (n - i - 1))) {
                ans = abs(pre / (i + 1) - suf / (n - i - 1));
                index = i;
            }
        }
        return index;
    }
};
int main() {
    // Solution()
    return 0;
}