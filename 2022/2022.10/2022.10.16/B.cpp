#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            string temp = to_string(nums[i]);
            reverse(temp.begin(), temp.end());
            nums.push_back(stoi(temp));
        }
        return unordered_set<int>(nums.begin(), nums.end()).size();
    }
};
int main() {
    vector<int> a{2, 2, 2};
    Solution().countDistinctIntegers(a);
    return 0;
}