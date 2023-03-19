#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int ans = 0;
        long long sum = 0;
        for (int& num : nums) {
            sum += num;
            if (sum <= 0) return ans;
            ++ans;
        }
        return ans;
    }
};
int main() { return 0; }