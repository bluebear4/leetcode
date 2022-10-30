#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    string oddString(vector<string>& words) {
        map<vector<int>, vector<string>> cnt;
        for (auto& word : words) {
            vector<int> x;
            for (int i = 1; i < word.length(); ++i) {
                x.emplace_back(word[i] - word[i - 1]);
            }
            cnt[x].emplace_back(word);
        }
        if (cnt.begin()->second.size() == 1) return cnt.begin()->second[0];
        return cnt.rbegin()->second[0];
    }
};
int main() {
    // Solution()
    return 0;
}