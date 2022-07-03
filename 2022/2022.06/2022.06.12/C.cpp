#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rall(x) x.rbegin(), x.rend()
class Solution {
#define all(x) x.begin(), x.end()
    int ans = 1e9;
    void dfs(vector<int>& now, vector<int>& cookies, set<vector<int>>& vis,
             int index) {
        if (index == cookies.size()) {
            ans = min(ans, *max_element(all(now)));
            return;
        }
        vector<int> temp(all(now));
        sort(all(temp));
        if (vis.count(temp)) return;
        vis.insert(temp);
        for (int i = 0; i < now.size(); ++i) {
            now[i] += cookies[index];
            dfs(now, cookies, vis, index + 1);
            now[i] -= cookies[index];
        }
    }

   public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> now(k, 0);
        set<vector<int>> vis;
        ans = 1e9;
        dfs(now, cookies, vis, 0);
        return ans;
    }
};
int main() {
    vector<int> a{8, 15, 10, 20, 8};
    Solution().distributeCookies(a, 2);
    return 0;
}