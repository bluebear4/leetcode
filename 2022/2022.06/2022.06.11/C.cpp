#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    bool matchReplacement(string s, string sub,
                          vector<vector<char>>& mappings) {
        unordered_map<int, unordered_set<int>> edge;
        for (auto& it : mappings) {
            edge[it[0]].insert(it[1]);
        }
        auto check = [&](int pos) {
            if (pos + sub.length() > s.length()) return false;
            for (int i = 1; i < sub.length(); ++i) {
                if (s[pos + i] != sub[i] && !edge[sub[i]].count(s[pos + i])) {
                    return false;
                }
            }
            return true;
        };
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == sub[0] || edge[sub[0]].count(s[i])) {
                if (check(i)) {
                    return true;
                }
            }
        }
        return false;
    }
};
int main() {
    // Solution()
    return 0;
}