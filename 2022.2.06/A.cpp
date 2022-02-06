#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> a, b;
        for (int i = 0; i < nums.size(); i += 2) {
            a.emplace_back(nums[i]);
            if (i + 1 < nums.size()) b.emplace_back(nums[i + 1]);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), greater<int>());
        for (int i = 0; i < nums.size(); i += 2) {
            nums[i] = a[i / 2];
            if (i + 1 < nums.size()) nums[i + 1] = b[i / 2];
        }
        return nums;
    }
};
int main() {
    // Solution()
    return 0;
}