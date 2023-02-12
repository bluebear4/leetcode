#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1,
                    int uniqueCnt2) {
        int x = divisor1 / gcd(divisor1, divisor2) * divisor2;
       // 10 -> /a !=0 /b == 0
       // 01 -> /a ==0 /b != 0
       // 11 -> /a !=0 /b != 0
       // 00 -> /x == 0
    }
};
int main() { return 0; }