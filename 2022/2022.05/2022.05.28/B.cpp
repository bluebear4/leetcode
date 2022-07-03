#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rall(x) x.rbegin(), x.rend()
class Solution {
#define all(x) x.begin(), x.end()
   public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        int n = messages.size();
        unordered_map<string, int> cnt;
        int maxx = 0;
        for (int i = 0; i < n; ++i) {
            cnt[senders[i]] += count(all(messages[i]), ' ') + 1;
            maxx = max(maxx, cnt[senders[i]]);
        }
        string ans;
        for (auto& [k, v] : cnt) {
            if (v == maxx) {
                ans = max(ans, k);
            }
        }
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}