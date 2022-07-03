#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()
// 0->0 0
// 0->1 0
// 1->0 0
// 1->1 1
class Solution {
   public:
    int maximumXOR(vector<int>& nums) {
        int ans = 0;
        for (auto& num : nums) ans |= num;
        return ans;
    }
};
int main(){
    //Solution()
    return 0;
}