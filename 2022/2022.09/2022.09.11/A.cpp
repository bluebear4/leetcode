#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int mostFrequentEven(vector<int>& nums) {
        int ans = -1;
        unordered_map<int, int> cnt;
        for (auto& num : nums) {
            if (num % 2 == 0) {
                ++cnt[num];
                if (cnt[num] > cnt[ans]) {
                    ans = num;
                } else if (cnt[num] == cnt[ans]) {
                    ans = min(ans, num);
                }
            }
        }
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}