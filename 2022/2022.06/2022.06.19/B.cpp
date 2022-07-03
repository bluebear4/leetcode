#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int minimumNumbers(int num, int k) {
        if (num == 0) return 0;
        for (int i = 1; i <= 10; ++i) {
            if (k * i % 10 == num % 10 && k * i <= num) {
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