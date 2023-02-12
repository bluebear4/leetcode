#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int distinctAverages(vector<int>& nums) {
        multiset<int> x(nums.begin(), nums.end());
        unordered_set<double> ans;
        while (x.size()) {
            ans.insert((*x.begin() + *x.rbegin()) / 2.0);
            x.erase(x.begin());
            x.erase(--x.end());
        }
        return ans.size();
    }
};
int main() {
    // Solution()
    return 0;
}