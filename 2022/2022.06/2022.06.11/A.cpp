#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rall(x) x.rbegin(), x.rend()
class Solution {
#define all(x) x.begin(), x.end()
   public:
    bool strongPasswordCheckerII(string password) {
        if (password.length() < 8) return false;
        if (count_if(all(password), [](int x) { return islower(x); }) == 0) {
            return false;
        }
        if (count_if(all(password), [](int x) { return isupper(x); }) == 0) {
            return false;
        }
        if (count_if(all(password), [](int x) { return isdigit(x); }) == 0) {
            return false;
        }
        if (count_if(all(password), [](int x) {
                string s = "!@#$%^&*()-+"s;
                for (auto &it : s)
                    if (x == it) return true;
                return false;
            }) == 0) {
            return false;
        }
        if(unique(all(password))!=password.end())return false;
        return true;
    }
};
int main() {
    // Solution()
    return 0;
}