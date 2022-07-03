#include <bits/stdc++.h>
using namespace std;
using ll = long long;
class Solution {
#define all(x) x.begin(), x.end()
    int dfs(unordered_map<int, int>& ans, int now) {
        if (ans[now] == now) return now;
        return ans[now] = dfs(ans, ans[now]);
    }

   public:
    vector<int> arrayChange(vector<int>& nums,
                            vector<vector<int>>& operations) {
        unordered_map<int, int> ans;
        for (auto& num : nums) ans[num] = num;
        reverse(all(operations));
        for (auto& op : operations) {
            ans[op[0]] = op[1];
            if (!ans.count(op[1])) ans[op[1]] = op[1];
            dfs(ans, op[0]);
        }
        for (auto& num : nums) num = ans[num];
        return nums;
    }
};
int main() {
    vector<int> a{1, 2};
    vector<vector<int>> b{{1, 3}, {2, 1}, {3, 2}};
    Solution().arrayChange(a, b);
    return 0;
}