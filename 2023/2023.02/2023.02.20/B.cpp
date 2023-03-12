#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    vector<int> divisibilityArray(string word, int m) {
        long long now = 0, n = word.length();
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            now = now * 10 + (word[i] - '0');
            now %= m;
            ans[i] = (now % m == 0);
        }
        return ans;
    }
};
int main() { return 0; }