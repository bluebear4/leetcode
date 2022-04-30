#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = n - 1; j > i; --j) {
                nums[j] += nums[j - 1];
                if (nums[j] >= 10) nums[j] -= 10;
            }
        }
        return nums.back();
    }
};
int main() {
    // Solution()
    return 0;
}