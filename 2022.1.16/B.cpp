#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int minMoves(int target, int maxDoubles) {
        int ans = 0;
        while (target > 1) {
            if (target & 1) {
                --target;
                ++ans;
            } else {
                if (maxDoubles) {
                    target >>= 1;
                    ++ans;
                    --maxDoubles;
                } else {
                    ans += target - 1;
                    break;
                }
            }
        }
        return ans;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    return 0;
}