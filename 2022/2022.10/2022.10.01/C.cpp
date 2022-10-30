#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() % 2 == 0) {
            if (nums2.size() % 2 == 0) return 0;
            int ans = 0;
            for (auto& it : nums1) ans ^= it;
            return ans;
        }
        int ans = 0;
        for (auto& it : nums2) ans ^= it;
        if (nums2.size() % 2 == 0) return ans;
        for (auto& it : nums1) ans ^= it;
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}