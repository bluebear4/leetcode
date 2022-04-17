#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rall(x) x.rbegin(), x.rend()
class Solution {
#define all(x) x.begin(), x.end()
   public:
    int largestInteger(int num) {
        vector<int> odd, even;
        for (auto it : to_string(num)) {
            int x = it - '0';
            if (x & 1) {
                odd.emplace_back(x);
            } else {
                even.emplace_back(x);
            }
        }
        sort(all(odd));
        sort(all(even));
        int ans = 0;
        for (auto it : to_string(num)) {
            int x = it - '0';
            if (x & 1) {
                ans = ans * 10 + odd.back();
                odd.pop_back();
            } else {
                ans = ans * 10 + even.back();
                even.pop_back();
            }
        }
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}