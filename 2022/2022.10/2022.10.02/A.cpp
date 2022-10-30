#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int commonFactors(int a, int b) {
        int ans = 0;
        for (int i = 1; i <= min(a, b); ++i) {
            if (a % i == 0 && b % i == 0) ++ans;
        }
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}