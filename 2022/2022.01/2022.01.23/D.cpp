#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int maxn = 3e5 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
    void dfs(vector<vector<int>>& statements, int now, unordered_set<int> good,
             unordered_set<int> bad, int& ans) {
        if (now == statements.size()) {
            ans = max<int>(good.size(), ans);
            return;
        }
        if (good.count(now)) {
            for (int j = 0; j < statements[now].size(); ++j) {
                if (statements[now][j] == 1) {
                    if (bad.count(j)) return;

                    good.insert(j);
                } else if (statements[now][j] == 0) {
                    if (good.count(j)) return;
                    bad.insert(j);
                }
            }
            dfs(statements, now + 1, good, bad, ans);
        } else if (bad.count(now)) {
            dfs(statements, now + 1, good, bad, ans);
        } else {
            bad.insert(now);
            dfs(statements, now + 1, good, bad, ans);
            bad.erase(now);
            good.insert(now);
            for (int j = 0; j < statements[now].size(); ++j) {
                if (statements[now][j] == 1) {
                    if (bad.count(j)) return;

                    good.insert(j);
                } else if (statements[now][j] == 0) {
                    if (good.count(j)) return;
                    bad.insert(j);
                }
            }
            dfs(statements, now + 1, good, bad, ans);
        }
    }

   public:
    int maximumGood(vector<vector<int>>& statements) {
        int ans = 0;
        unordered_set<int> good;
        unordered_set<int> bad;
        dfs(statements, 0, good, bad, ans);
        return ans;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    vector<vector<int>> a{{2, 0, 2, 2, 0},
                          {2, 2, 2, 1, 2},
                          {2, 2, 2, 1, 2},
                          {1, 2, 0, 2, 2},
                          {1, 0, 2, 1, 2}};
    Solution().maximumGood(a);
    return 0;
}