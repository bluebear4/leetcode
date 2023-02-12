#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> ans;
        for (auto& num : nums) {
            for (int i = 2; i * i <= num; ++i) {
                while (num % i == 0) {
                    ans.insert(i);
                    num /= i;
                }
            }
            if (num > 1) ans.insert(num);
        }
        return ans.size();
    }
};
int main() { return 0; }