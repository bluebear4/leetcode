#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<int, int> cnt, cnt2;
        for (auto &it : s) cnt[it]++;
        for (auto &it : target) cnt2[it]++;
        int ans = 1e9;
        for (auto &[k, m] : cnt2) {
            ans = min(ans, cnt[k] / m);
        }
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}