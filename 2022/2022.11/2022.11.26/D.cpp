#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int countPalindromes(string s) {
        static const int mod = 1e9 + 7;
        int n = s.length();
        // 00-99
        vector<vector<int>> L(n, vector<int>(100));
        vector<vector<int>> R(n, vector<int>(100));
        {
            vector<int> cnt(10);
            for (int i = 0; i < n; ++i) {
                int r = s[i] - '0';
                for (int l = 0; l < 100; l += 10) {
                    L[i][l + r] += cnt[l / 10];
                }
                cnt[r]++;
            }
        }
        {
            vector<int> cnt(10);
            for (int i = n - 1; i >= 0; --i) {
                int r = s[i] - '0';
                for (int l = 0; l < 100; l += 10) {
                    R[i][l + r] += cnt[l / 10];
                }
                cnt[r]++;
            }
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < 100; ++j) {
                L[i][j] += L[i - 1][j];
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j < 100; ++j) {
                R[i][j] += R[i + 1][j];
            }
        }
        long long ans = 0;
        for (int i = 2; i + 1 < n; ++i) {
            for (int x = 0; x < 100; ++x) {
                ans += 1ll * L[i - 1][x] * R[i + 1][x];
                ans %= mod;
            }
        }
        return ans;
    }
};
int main() {
    Solution().countPalindromes("103301");
    return 0;
}