#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rall(x) x.rbegin(), x.rend()
class Solution {
#define all(x) x.begin(), x.end()
   public:
    string removeStars(string s) {
        vector<char> stk;
        for (auto &it : s) {
            if (it != '*') {
                stk.push_back(it);
                continue;
            }
            if (stk.size()) stk.pop_back();
        }
        return string(all(stk));
    }
};
int main() {
    // Solution()
    return 0;
}