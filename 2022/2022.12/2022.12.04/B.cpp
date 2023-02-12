#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    long long dividePlayers(vector<int> &skill) {
        int sum = accumulate(skill.begin(), skill.end(), 0);
        if (2 * sum % skill.size() != 0) return -1;
        int want = 2 * sum / skill.size();
        unordered_map<int, int> cnt;
        for (auto &s : skill) cnt[s]++;
        long long ans = 0;
        for (auto &[k, v] : cnt) {
            while (v != 0) {
                --v;
                if (cnt[want - k]-- <= 0) return -1;
                ans += 1ll * k * (want - k);
            }
        }
        return ans;
    }
};

int main() {
    vector<int> a{10, 14, 16, 15, 9, 4, 4, 4};
    Solution().dividePlayers(a);
    return 0;
}