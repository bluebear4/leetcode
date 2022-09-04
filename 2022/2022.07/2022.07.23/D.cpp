#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rall(x) x.rbegin(), x.rend()
class Solution {
#define all(x) x.begin(), x.end()
   public:
    int shortestSequence(vector<int>& rolls, int k) {
        unordered_set<int> nums;
        reverse(all(rolls));
        int ans = 1;
        for (auto& it : rolls) {
            nums.insert(it);
            if (nums.size() == k) {
                nums.clear();
                ++ans;
            }
        }

        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}