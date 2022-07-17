#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (auto num : nums) {
            cnt[num]++;
        }
        vector<int> ans(2);
        for (auto& [k, v] : cnt) {
            ans[0] += v / 2;
            ans[1] += v % 2;
        }
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}