#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers,
                                 vector<int>& persons) {
        map<int, int> pos;
        for (auto& flower : flowers) {
            pos[flower[0]]++;
            pos[flower[1] + 1]--;
        }

        int n = persons.size();
        vector<int> ans(n);
        vector<int> ids(n);
        iota(ids.begin(), ids.end(), 0);

        sort(ids.begin(), ids.end(),
             [&](int x, int y) { return persons[x] < persons[y]; });

        auto it = pos.begin();
        int now = 0;
        for (auto& id : ids) {
            while (it != pos.end() && it->first <= persons[id]) {
                now += it->second;
                ++it;
            }
            ans[id] = now;
        }

        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}