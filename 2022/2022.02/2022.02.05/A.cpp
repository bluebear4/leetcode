#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int minimumSum(int num) {
        string s = to_string(num);
        int ans = 9999;
        for (int i = 0; i < 4; ++i) {
            for (int j = i + 1; j < 4; ++j) {
                int val = min(s[i] - '0', s[j] - '0') * 10 +
                          max(s[i] - '0', s[j] - '0');
                vector<int> t;
                for (int k = 0; k < 4; ++k) {
                    if (k == i || k == j) continue;
                    t.emplace_back(s[k] - '0');
                }
                val += min(t[0], t[1]) * 10 + max(t[0], t[1]);
                ans = min(ans, val);
            }
        }
        return ans;
    }
};
int main() {
    // Solution()

    return 0;
}