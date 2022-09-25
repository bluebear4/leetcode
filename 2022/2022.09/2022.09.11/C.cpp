#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rall(x) x.rbegin(), x.rend()
class Solution {
#define all(x) x.begin(), x.end()
   public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(all(intervals));
        multiset<int> r;
        r.insert(-1);
        for (auto& vec : intervals) {
            if (vec[0] < *r.begin()) {
                r.insert(vec[1]);
            } else {
                r.erase(--r.lower_bound(vec[0]));
                r.insert(vec[1]);
            }
        }
        return r.size();
    }
};
int main() {
    vector<vector<int>> a{{5, 10}, {6, 8}, {1, 5}, {2, 3}, {1, 10}};
    Solution().minGroups(a);
    return 0;
}