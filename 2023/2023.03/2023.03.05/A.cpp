#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int passThePillow(int n, int time) {
        int now = 1, add = 1;
        while (time--) {
            now += add;
            if (now == n) {
                add = -1;
            }
            if (now == 1) {
                add = 1;
            }
        }
        return now;
    }
};
int main() { return 0; }