#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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

   public:
    int minScore(int n, vector<vector<int>>& roads) {
        Disjoint_Set_Union d(n);
        for (auto& v : roads) {
            d.Merge(v[0], v[1]);
        }
        int ans = INT_MAX;
        for (auto& v : roads) {
            if (d.Find(1) == d.Find(v[0])) ans = min(ans, v[2]);
        }
        return ans;
    }
};
int main() {
    // Solution().mostProfitablePath(G, 47, a);
    return 0;
}