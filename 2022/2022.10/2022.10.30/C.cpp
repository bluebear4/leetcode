#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
    long long pow10(int x) {
        long long ret = 1;
        for (int i = 0; i < x; ++i) {
            ret *= 10;
        }
        return ret;
    }

   public:
    long long makeIntegerBeautiful(long long n, int target) {
        string s = to_string(n);
        int sum = 0;
        long long ans = 0;
        for (auto &it : s) sum += it - '0';

        if (sum <= target) return ans;

        reverse(s.begin(), s.end());
        for (int i = 0; i < s.length() && sum > target; ++i) {
            if (s[i] - '0' == 0) continue;
            if (s[i] - '0' == 10) {
                sum -= 9;
                if (i + 1 < s.length()) {
                    s[i + 1]++;
                } else {
                    s.push_back('1');
                }
                continue;
            }

            sum -= s[i] - '0' - 1;

            ans += pow10(i) * (10 - s[i] + '0');
            if (i + 1 < s.length()) {
                s[i + 1]++;
            } else {
                s.push_back('1');
            }
        }

        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}