#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    vector<int> evenOddBit(int n) {
        vector<int> ans(2);
        int now = 0;
        while (n) {
            if (n & 1) ans[now & 1]++;
            now++;
            n >>= 1;
        }
        return ans;
    }
};
int main() { return 0; }