#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> vis;
        map<int, set<int>> index;
        for (int i = 0; i < n; ++i) index[nums[i]].insert(i);
        long long ans = 0;
        while (vis.size() != n) {
            if (index.begin()->second.empty()) {
                index.erase(index.begin());
                continue;
            }
            int chose = *(index.begin()->second.begin());
            index.begin()->second.erase(index.begin()->second.begin());
            if (vis.count(chose)) continue;
            ans += nums[chose];
            vis.insert(chose);
            if (chose - 1 >= 0) vis.insert(chose - 1);
            if (chose + 1 < n) vis.insert(chose + 1);
        }
        return ans;
    }
};
int main() {
    vector<int> a{2, 1, 3, 4, 5, 2};
    Solution().findScore(a);
    return 0;
};
