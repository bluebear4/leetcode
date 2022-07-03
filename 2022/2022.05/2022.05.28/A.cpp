#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    bool digitCount(string num) {
        unordered_map<int, int> cnt;
        for (auto &it : num) cnt[it]++;
        for (int i = 0; i < num.length(); ++i) {
            if (cnt[i + '0'] != num[i] - '0') return false;
        }
        return true;
    }
};
int main() {
    // Solution()
    return 0;
}