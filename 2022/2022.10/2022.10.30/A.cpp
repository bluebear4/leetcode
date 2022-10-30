#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int averageValue(vector<int>& nums) {
        int ans = 0, cnt = 0;
        for (auto& num : nums) {
            if (num % 2 == 0 && num % 3 == 0) {
                ++cnt;
                ans += num;
            }
        }
        if (cnt == 0) return 0;
        return ans / cnt;
    }
};
int main() {
    // Solution()
    return 0;
}