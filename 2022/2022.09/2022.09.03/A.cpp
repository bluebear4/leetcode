#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    bool findSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> vis;
        for (int i = 0; i + 1 < n; ++i) {
            int sum = nums[i] + nums[i + 1];
            if (vis.count(sum)) return true;
            vis.insert(sum);
        }
        return false;
    }
};
int main() {
    // Solution()
    return 0;
}