#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
    class Disjoint_Set_Union {
       public:
        vector<int> father;
        int n;
        void init() {
            for (int i = 0; i <= n; i++) father[i] = i;
            return;
        }
        Disjoint_Set_Union(int _n) : n(_n), father(_n + 1) { init(); }
        int Find(int x) {
            return father[x] == x ? x : father[x] = Find(father[x]);
        }
        void Merge(int x, int y) {
            int fx = Find(x);
            int fy = Find(y);
            father[fy] = fx;
            return;
        }
    };
    using ll = long long;

   public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        ll ans = 1ll * n * (n - 1) / 2;
        Disjoint_Set_Union dsu{n};
        for (auto& edge : edges) {
            dsu.Merge(edge[0], edge[1]);
        }
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; ++i) {
            cnt[dsu.Find(i)]++;
        }
        for (auto& [k, v] : cnt) {
            ans -= 1ll * v * (v - 1) / 2;
        }
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}