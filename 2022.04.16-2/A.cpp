#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int findClosestNumber(vector<int>& nums) {
        return *min_element(nums.begin(), nums.end(), [](int x, int y) {
            if (abs(x) != abs(y)) return abs(x) < abs(y);
            return x > y;
        });
    }
};
int main() {
    // Solution()
    return 0;
}