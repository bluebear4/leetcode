#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rall(x) x.rbegin(), x.rend()
class Solution {
#define all(x) x.begin(), x.end()
   public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        if (count(all(suits), suits[0]) == suits.size()) {
            return "Flush";
        }
        unordered_map<int, int> cnt;
        for (auto& it : ranks) cnt[it]++;

        unordered_map<int, int> num;
        for (auto& [k, v] : cnt) {
            num[v]++;
        }

        if (num.count(3) || num.count(4) || num.count(5))
            return "Three of a Kind";
        if (num.count(2)) return "Pair";
        return "High Card";
    }
};
int main() {
    // Solution()
    return 0;
}