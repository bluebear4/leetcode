#include <bits/stdc++.h>
using namespace std;
class Solution {
    bool f(string& s) {
        static set<int> vis{'a', 'e', 'i', 'o', 'u'};
        return vis.count(s[0]) && vis.count(s.back());
    }

   public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int ans = 0;
        for (int i = left; i <= right; ++i) {
            ans += f(words[i]);
        }
        return ans;
    }
};
int main() { return 0; }