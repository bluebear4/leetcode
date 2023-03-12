#include <bits/stdc++.h>
using namespace std;
class Solution {
    constexpr static int mod = 1e9 + 7;
    bool ok(int x) {
        for (int i = 2; i * i <= x; ++i) {
            if (x % (i * i) == 0) return false;
            if (x % i == 0) x /= i;
        }
        return true;
    }

   public:
    int squareFreeSubsets(vector<int>& nums) {
        unordered_map<long long, int> ans;
        for (auto& it : nums) {
            if (!ok(it)) continue;
            unordered_map<long long, int> tmp;
            tmp[it]++;
            for (auto& [k, v] : ans) {
                if (gcd(k, it) == 1) {
                    tmp[k * it] += v;
                }
            }
            for (auto& [k, v] : tmp) (ans[k] += v) %= mod;
        }
        int t = 0;
        for (auto& [k, v] : ans) (t += v) %= mod;
        return t;
    }
};
int main() { return 0; };
