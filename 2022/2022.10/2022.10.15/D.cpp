#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
    //子树划分之后 包含当前节点剩余联通块的和
    int dfs(const vector<vector<int>>& G, const vector<int>& v, int now,
            int want, vector<int>& vis) {
        int sum = v[now];
        for (auto& it : G[now]) {
            if (vis[it]) continue;
            vis[now] = 1;
            int temp = dfs(G, v, it, want, vis);
            vis[it] = 0;

            if (temp == -1) return -1;
            sum += temp;
        }
        if (sum < want) return sum;
        if (sum == want) return 0;
        return -1;
    }

   public:
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> G(n);
        for (auto& it : edges) {
            G[it[0]].push_back(it[1]);
            G[it[1]].push_back(it[0]);
        }

        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> vis(n);
        int ans = 0;
        for (int i = 1; i * i <= sum; ++i) {
            if (sum % i == 0) {
                vis[0] = 1;
                if (dfs(G, nums, 0, i, vis) == 0) {
                    return sum / i - 1;
                }
                vis[0] = 0;

                vis[0] = 1;
                if (dfs(G, nums, 0, sum / i, vis) == 0) {
                    ans = i - 1;
                }
                vis[0] = 0;
            }
        }
        return ans;
    }
};
int main() {
    vector<int> a{6, 2, 2, 2, 6};
    vector<vector<int>> G{{0, 1}, {1, 2}, {1, 3}, {3, 4}};
    Solution().componentValue(a, G);
    return 0;
}