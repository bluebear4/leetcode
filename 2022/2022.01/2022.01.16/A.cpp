#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        for (int i = 0; i < s.length(); i += k) {
            ans.emplace_back(s.substr(i, k));
        }
        ans.back() += string(k - ans.back().length(), fill);
        return ans;
    }
};
int main() { return 0; }