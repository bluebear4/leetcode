#include <bits/stdc++.h>
using namespace std;
using ll = long long;
class Solution {
#define all(x) x.begin(), x.end()
   public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int gcd = numsDivide[0];
        for (auto& it : numsDivide) {
            gcd = __gcd(gcd, it);
        }
        sort(all(nums));
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (gcd % nums[i] != 0){
                ++ans;
            }else{
                return ans;
            }
        }
        return -1;
    }
};
int main() {
    return 0;
}