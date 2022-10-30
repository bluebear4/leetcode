#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int, int> cnt;
        for (auto& num : nums) cnt[num % space]++;

        map<int, unordered_set<int> > sort_cnt;
        for (auto& [k, v] : cnt) sort_cnt[v].insert(k);
        int ans = 1e9;
        for (auto& num : nums) {
            if (sort_cnt.rbegin()->second.count(num % space)) {
                ans = min(ans, num);
            }
        }
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}