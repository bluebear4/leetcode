#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> n(nums.begin(), nums.end());
        for (int i = 1000; i >= 1; --i) {
            if (n.count(i) && n.count(-i)) {
                return i;
            }
        }
        return -1;
    }
};
int main() {
    // Solution()
    return 0;
}