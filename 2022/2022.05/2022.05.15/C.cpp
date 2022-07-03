#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rall(x) x.rbegin(), x.rend()
class Solution {
#define all(x) x.begin(), x.end()
   public:
    int largestCombination(vector<int>& nums) {
        vector<int> ans(32, 0);
        for (auto& num : nums) {
            for (int i = 0; i < 32; ++i) {
                ans[i] += (num & 1);
                num >>= 1;
            }
        }
        return *max_element(all(ans));
    }
};
int main() {
    // Solution()
    return 0;
}