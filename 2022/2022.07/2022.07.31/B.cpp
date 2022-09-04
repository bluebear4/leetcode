#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rall(x) x.rbegin(), x.rend()
class Solution {
#define all(x) x.begin(), x.end()
   public:
    int maximumGroups(vector<int>& grades) {
        int ans = 0;
        for (int i = 1;; ++i) {
            ans += i;
            if (ans > grades.size()) return i - 1;
        }
        return -1;
    }
};
int main() {
    // Solution()
    return 0;
}