#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    vector<string> cellsInRange(string s) {
        vector<string> ans;
        for (int i = s[0]; i <= s[3]; ++i) {
            for (int j = s[1]; j <= s[4]; ++j) {
                string s(1, i);
                s += j;
                ans.emplace_back(s);
            }
        }
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}