#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    string removeDigit(string number, char digit) {
        int pos = -1, n = number.length();
        string ans;
        for (int i = 0; i < n; ++i) {
            if (number[i] != digit) continue;
            string temp = number.substr(0, pos) + number.substr(pos + 1);
            if (temp > ans) {
                ans.swap(temp);
            }
        }
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}