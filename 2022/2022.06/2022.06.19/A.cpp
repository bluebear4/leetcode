#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    string greatestLetter(string s) {
        unordered_set<int> vis(s.begin(), s.end());
        for (int i = 'z'; i >= 'a'; --i) {
            if (vis.count(i) && vis.count(i + 'A' - 'a')) {
                return string(1, i + 'A' - 'a');
            }
        }
        return ""s;
    }
};
int main() {
    // Solution()
    return 0;
}