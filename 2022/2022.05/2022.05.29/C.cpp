#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int totalSteps(vector<int>& nums) {
        list<int> L(all(nums));
        queue<list<int>::iterator> q;
        while (q.size()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                auto it = q.front();
                q.pop();
                if (next(it, 1) != L.end() && *it > *next(it, 1)) {
                    L.erase(next(it, 1));
                    q.push(it);
                }
            }
        }
    }
};
int main() {
    // Solution()
    return 0;
}