#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> diff(n + 1);
        for (auto shift : shifts) {
            if (shift[2]) {
                diff[shift[0]]++;
                diff[shift[1] + 1]--;
            } else {
                diff[shift[0]]--;
                diff[shift[1] + 1]++;
            }
        }
        for (int i = 0, now = 0; i <= n; ++i) {
            now += diff[i];
            now %= 26;
            now += 26;
            now %= 26;
            s[i] = (s[i] - 'a' + now) % 26 + 'a';
        }
        return s;
    }
};
int main() {
    // Solution()
    return 0;
}