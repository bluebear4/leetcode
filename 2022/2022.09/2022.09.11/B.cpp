#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int partitionString(string s) {
        unordered_set<int> vis;
        int ans = 1;
        for (auto &it : s) {
            if (vis.count(it)) {
                vis.clear();
                ++ans;
            }
            vis.insert(it);
        }
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}