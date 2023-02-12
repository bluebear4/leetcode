#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int pivotInteger(int n) {
        int sum = n * (n + 1) / 2;
        for (int i = 1; i <= n; ++i) {
            if (i * (i + 1) == sum + i) {
                return i;
            }
        }
        return -1;
    }
};
int main() {
    // Solution()
    return 0;
}