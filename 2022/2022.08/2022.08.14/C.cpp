#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
    bool dfs(const string &pattern, int now, string &ans,
             unordered_set<int> &used) {
        if (pattern.length() == now) {
            return true;
        }
        if (now == -1) {
            for (int i = '1'; i <= '9'; ++i) {
                if (used.count(i)) continue;
                used.insert(i);
                ans += i;
                if (dfs(pattern, now + 1, ans, used)) return true;
                ans.pop_back();
                used.erase(i);
            }
        } else if (pattern[now] == 'I') {
            for (int i = ans[now] + 1; i <= '9'; ++i) {
                if (used.count(i)) continue;
                used.insert(i);
                ans += i;
                if (dfs(pattern, now + 1, ans, used)) return true;
                ans.pop_back();
                used.erase(i);
            }
        } else {
            for (int i = '1'; i < ans[now]; ++i) {
                if (used.count(i)) continue;
                used.insert(i);
                ans += i;
                if (dfs(pattern, now + 1, ans, used)) return true;
                ans.pop_back();
                used.erase(i);
            }
        }
        return false;
    }

   public:
    string smallestNumber(string pattern) {
        string ans;
        unordered_set<int> used;
        dfs(pattern, -1, ans, used);
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}