#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
    bool check(const string &s) {
        unordered_map<int, int> cnt;
        for (auto &it : s) cnt[it]++;
        unordered_map<int, int> cnt_cnt;
        for (auto &it : cnt) cnt_cnt[it.second]++;
        return cnt_cnt.size() == 1;
    }

   public:
    bool equalFrequency(string word) {
        for (int i = 0; i < word.length(); ++i) {
            if (check(word.substr(0, i) + word.substr(i + 1))) return true;
        }

        return false;
    }
};
int main() {
    // Solution()
    return 0;
}