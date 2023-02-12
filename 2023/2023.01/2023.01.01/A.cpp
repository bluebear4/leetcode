#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int countDigits(int num) {
        string s = to_string(num);
        int ans = 0;
        for (auto &it : s) {
            if (it == '0') continue;
            ans += num % (it - '0') == 0;
        }
        return ans;
    }
};
int main() { return 0; }