#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int, int> cnt;
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == key) {
                if (++cnt[nums[i + 1]] > cnt[ans]) {
                    ans = nums[i + 1];
                }
            }
        }
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}