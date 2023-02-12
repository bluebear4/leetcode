#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int numberOfCuts(int n) {
        if (n == 1) return 0;
        if (n & 1) return n;
        return n >> 1;
    }
};
int main() {
    // Solution()
    return 0;
}