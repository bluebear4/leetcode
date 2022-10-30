#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == k) ++ans;
            int now = nums[i];
            for (int j = i + 1; j < n; ++j) {
                now = __gcd(now, nums[j]);
                if (now == k) ans++;
            }
        }
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}