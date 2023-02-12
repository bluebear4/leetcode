#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    vector<string> splitMessage(string message, int limit) {
        constexpr int other = 3;  // </>

        for (int len = 1;; ++len) {
            int count = 1;
            if (limit <= other + 2 * len) {
                break;
            }

            int now = 0;
            while (now < message.length()) {
                now += limit - to_string(count).length() - other - len;
                count++;
            }

            --count;
            if (to_string(count).length() != len) continue;

            vector<string> ans;
            for (int i = 1, now = 0; i <= count; ++i) {
                int diff = limit - to_string(i).length() - other - len;
                ans.emplace_back(message.substr(now, diff) + "<" +
                                 to_string(i) + "/" + to_string(count) + ">");
                now += diff;
            }
            return ans;
        }
        return {};
    }
};
int main() {
    string s(10000, '2');
    Solution().splitMessage(s, 10);
    return 0;
}