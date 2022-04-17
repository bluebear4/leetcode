#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    string digitSum(string s, int k) {
        if (s.length() <= k) return s;
        string t;
        for (int i = 0; i < s.length(); i += k) {
            int num = 0;
            for (auto &it : s.substr(i, min<int>(k, s.length() - i))) {
                num += it - '0';
            }
            t += to_string(num);
        }
        return digitSum(t, k);
    }
};
int main() {
    // Solution()
    return 0;
}