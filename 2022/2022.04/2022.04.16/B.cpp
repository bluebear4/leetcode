#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int perfectMenu(vector<int>& materials, vector<vector<int>>& cookbooks,
                    vector<vector<int>>& attribute, int limit) {
        int n = cookbooks.size(), ans = -1;
        for (int i = 0; i < (1 << n); ++i) {
            vector<int> temp = materials;
            int l = 0, value = 0;
            for (int j = 0; j < n; ++j) {
                if (i >> j & 1) {
                    for (int k = 0; k < 5; ++k) {
                        temp[k] -= cookbooks[j][k];
                    }
                    if (*min_element(temp.begin(), temp.end()) < 0) break;
                    value += attribute[j][0];
                    l += attribute[j][1];
                    if (l >= limit) {
                        ans = max(ans, value);
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    // Solution()
    return 0;
}