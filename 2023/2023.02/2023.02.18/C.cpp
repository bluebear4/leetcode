#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int minImpossibleOR(vector<int>& nums) {
        int ans = 1;
        auto check = [&nums](int x) {
            int now = 0;
            for (int& num : nums) {
                if ((num | x) == x) {
                    now |= num;
                }
            }
            return now == x;
        };
        while (check(ans)) {
            ans >>= 1;
        }
        return ans;
    }
};
int main() { return 0; };
