#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for (auto& num : nums) {
            string s = to_string(num);
            for (auto& it : s) {
                ans.emplace_back(it - '0');
            }
        }
        return ans;
    }
};
int main() { return 0; }