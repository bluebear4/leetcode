#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int minMovesToMakePalindrome(string s) {
        list<int> lst(s.begin(), s.end());
        unordered_map<int, int> cnt;
        for (auto &it : lst) cnt[it]++;
        bool flag = false;
        int ans = 0;
        for (auto l = lst.begin(); l != lst.end();) {
            if (cnt[*l] == 1) {
                flag = true;
                ++l;
                continue;
            }
            auto r = --lst.end();
            while (*r != *l) {
                --r;
                ++ans;
            }
            --cnt[*l];
            --cnt[*r];
            lst.erase(r);
            l = lst.erase(l);
            if (flag) ++ans;
        }
        return ans;
    }
};
int main() {
    Solution().minMovesToMakePalindrome("scpcyxprxxsjyjrww");
    return 0;
}