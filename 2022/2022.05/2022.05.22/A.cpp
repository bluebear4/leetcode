#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rall(x) x.rbegin(), x.rend()
class Solution {
#define all(x) x.begin(), x.end()
   public:
    int percentageLetter(string s, char letter) {
        return count(all(s), letter) * 100 / s.length();
    }
};
int main() {
    // Solution()
    return 0;
}