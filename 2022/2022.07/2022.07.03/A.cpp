#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rall(x) x.rbegin(), x.rend()
class Solution {
#define all(x) x.begin(), x.end()
   public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> hs;
        int now = 'a';
        for (auto &k : key) {
            if (hs.count(k) || k == ' ') continue;
            hs[k] = now++;
        }
        for (auto &it : message) {
            if (it == ' ') continue;
            it = hs[it];
        }
        return message;
    }
};
int main() {
    Solution().decodeMessage("the quick brown fox jumps over the lazy dog",
                             "as");
    return 0;
}