#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;
        for (auto& it : nums) {
            ans.push_back(it);
            while (ans.size() >= 2) {
                int x = ans.back();
                ans.pop_back();
                int y = ans.back();
                ans.pop_back();
                int gcd = __gcd(x, y);
                if (gcd == 1) {
                    ans.push_back(y);
                    ans.push_back(x);
                    break;
                } else {
                    ans.push_back(x / gcd * y);
                }
            }
        }
        return ans;
    }
};
int main() {
    vector<int> a{2, 2, 1, 1, 3, 3, 3};
    Solution().replaceNonCoprimes(a);
    return 0;
}