#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        for (int i = 0, now = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                ans += ++now;
            }else{
                now = 0;
            }
        }
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}