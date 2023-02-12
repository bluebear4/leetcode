#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int takeCharacters(string s, int k) {
        int n = s.length();
        vector<vector<int>> cnt(n, vector<int>(3));
        for (int i = 0; i < n; ++i) {
            cnt[i][s[i] - 'a']++;
            if (i) {
                cnt[i][0] += cnt[i - 1][0];
                cnt[i][1] += cnt[i - 1][1];
                cnt[i][2] += cnt[i - 1][2];
            }
        }

        auto get_cnt = [&cnt, &n](int a, int b, int c) {
            if (a <= 0 && b <= 0 && c <= 0) return 0;
            int l = 0, r = n - 1, mid, ans = -1;
            while (l <= r) {
                mid = (l + r) >> 1;
                if (cnt[mid][0] >= a && cnt[mid][1] >= b && cnt[mid][2] >= c) {
                    ans = mid + 1;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            return ans;
        };
        int ans = get_cnt(k, k, k);
        if (ans == -1) return -1;

        for (int i = n - 1, a = k, b = k, c = k; i >= 0; --i) {
            switch (s[i] - 'a') {
                case 0:
                    a--;
                    break;
                case 1:
                    b--;
                    break;
                case 2:
                    c--;
                    break;

                default:
                    assert(false);
            }
            int temp = get_cnt(a, b, c);
            if (temp == -2 || temp >= i) continue;
            ans = min(ans, n - i + temp);
        }
        return ans;
    }
};
int main() {
    Solution().takeCharacters("a", 0);
    return 0;
}