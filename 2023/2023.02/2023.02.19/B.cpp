#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int minOperations(int n) {
        vector<int> bits;
        for (int i = n; i > 0; i >>= 1) {
            bits.emplace_back(i & 1);
        }
        int ans = 0;
        for (int i = 0; i < bits.size(); ++i) {
            if (bits[i] == 1) {
                int j = i;
                while (j < bits.size() && bits[j] == 1) ++j;
                if (j - i > 1) {
                    ++ans;
                    for (int k = i; k < j; ++k) {
                        bits[k] = 0;
                    }
                    if (j < bits.size())
                        bits[j] = 1;
                    else
                        bits.emplace_back(1);
                }
            }
        }
        return ans + count(bits.begin(), bits.end(), 1);
    }
};
int main() {
    Solution().minOperations(39);
    return 0;
}