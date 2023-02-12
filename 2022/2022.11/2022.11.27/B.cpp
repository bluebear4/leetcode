#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int appendCharacters(string s, string t) {
        int j = 0;
        for (int i = 0; i < s.length() && j < t.length(); ++i) {
            if (s[i] == t[j]) {
                ++j;
            }
        }
        return t.length() - j;
    }
};
int main() {
    // Solution()
    return 0;
}