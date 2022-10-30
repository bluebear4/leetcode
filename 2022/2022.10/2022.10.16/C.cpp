#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
    int reverse_int(int x) {
        int ret = 0;
        while (x) {
            ret = ret * 10 + x % 10;
            x /= 10;
        }
        return ret;
    }

   public:
    bool sumOfNumberAndReverse(int num) {
        for (int i = 0; i <= num; ++i) {
            if (i + reverse_int(i) == num) return true;
        }
        return false;
    }
};
int main() {
    // Solution()
    return 0;
}