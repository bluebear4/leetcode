#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int minMaxGame(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int n = nums.size();
        vector<int> a(n / 2);
        for (int i = 0; i < n / 2; ++i) {
            if (i & 1)
                a[i] = max(nums[2 * i], nums[2 * i + 1]);
            else
                a[i] = min(nums[2 * i], nums[2 * i + 1]);
        }
        return minMaxGame(a);
    }
};
int main() {
    // Solution()
    return 0;
}