#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int largestVariance(string s) {
        vector<int> pos[26];
        for (int i = 0; i < s.length(); ++i) {
            pos[s[i] - 'a'].emplace_back(i);
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                
            }
        }
        return ans;
    }
};
int main() {
    Solution().largestVariance("aababbb");
    return 0;
}