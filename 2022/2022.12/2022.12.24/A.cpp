#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int captureForts(vector<int>& forts) {
        int n = forts.size(), ans = 0;
        set<int> pos;
        for (int i = 0; i < n; ++i) {
            if (forts[i] != 0) pos.insert(i);
        }
        for (auto it = pos.begin(); it != pos.end(); ++it) {
            auto nxt = next(it, 1);
            if (nxt == pos.end() || forts[*it] != 1 || forts[*nxt] != -1)
                continue;
            ans = max(ans, abs(*nxt - *it) - 1);
        }
        for (auto it = pos.rbegin(); it != pos.rend(); ++it) {
            auto nxt = next(it, 1);
            if (nxt == pos.rend() || forts[*it] != 1 || forts[*nxt] != -1)
                continue;
            ans = max(ans, abs(*nxt - *it) - 1);
        }
        return ans;
    }
};
int main() { return 0; }