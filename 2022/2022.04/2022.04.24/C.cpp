#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
    class BIT {
       public:
        vector<int> tree;
        int n, size;
        BIT(int _n) : size(0), n(_n), tree(_n + 1, 0) {}
        static int lowbit(int x) { return x & (-x); }
        int query(int x) {
            int ans = 0;
            while (x) {
                ans += tree[x];
                x -= lowbit(x);
            }
            return ans;
        }
        void add(int x, int val) {
            while (x <= n) {
                tree[x] += val;
                x += lowbit(x);
            }
            size += val;
        }
    };

   public:
    vector<int> countRectangles(vector<vector<int>>& r,
                                vector<vector<int>>& p) {
        vector<int> lsh;
        for (auto& it : p) {
            lsh.emplace_back(it[1]);
            lsh.emplace_back(it[1] - 1);
        }
        for (auto& it : r) {
            lsh.emplace_back(it[1] - 1);
        }
        sort(lsh.begin(), lsh.end());
        lsh.erase(unique(lsh.begin(), lsh.end()), lsh.end());
        auto change = [&lsh](int x) {
            return lower_bound(lsh.begin(), lsh.end(), x) - lsh.begin() + 1;
        };
        BIT T(lsh.size());

        sort(r.begin(), r.end(), greater<vector<int>>());

        int n = p.size();
        vector<int> ids(n);
        iota(ids.begin(), ids.end(), 0);
        sort(ids.begin(), ids.end(), [&](int x, int y) { return p[x] < p[y]; });

        vector<int> ans(n);

        int index = 0;
        for (auto& id : ids) {
            while (index < r.size() && r[index][0] >= p[id][0]) {
                T.add(change(r[index++][1]), 1);
            }
            while (index - 1 >= 0 && r[index - 1][0] < p[id][0]) {
                T.add(change(r[--index][1]), -1);
            }
            ans[id] = T.size - T.query(change(p[id][1] - 1));
        }
        return ans;
    }
};
int main() {
    vector<vector<int>> a{{1, 2}, {2, 3}, {2, 5}};
    vector<vector<int>> b{{2, 1}, {1, 4}};
    Solution().countRectangles(a, b);
    return 0;
}