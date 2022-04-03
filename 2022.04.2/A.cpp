#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
    int CountOnes(int n) {
        int count = 0;
        while (n) {
            ++count;
            n = n & (n - 1);
        }
        return count;
    }

   public:
    int minBitFlips(int start, int goal) { return CountOnes(start ^ goal); }
};
int main() {
    // Solution()
    return 0;
}