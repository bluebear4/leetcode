#include <bits/stdc++.h>
using namespace std;
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
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        Disjoint_Set_Union d(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j && lcp[i][j] != n - i) return "";
                if (lcp[i][j] != lcp[j][i]) return "";
                if (i - 1 >= 0 && j - 1 >= 0 && lcp[i - 1][j - 1] != 0 &&
                    lcp[i][j] != lcp[i - 1][j - 1] - 1)
                    return "";
                if (lcp[i][j] > n - max(i, j)) return "";
                if (lcp[i][j] != 0) d.Merge(i, j);
            }
        }
        vector<int> a(n);
        for (int i = 0, now = 'a'; i < n; ++i) {
            if (a[i] == 0) {
                if (now > 'z') return "";
                for (int j = i; j < n; ++j) {
                    if (d.Find(i) == d.Find(j)) {
                        a[j] = now;
                    }
                }
                ++now;
            }
        }
        return string(a.begin(), a.end());
    }
};
/**
[[8,0,0,0,0,1,2,0]
,[0,7,0,1,1,0,0,1]
,[0,0,6,0,0,0,0,0]
,[0,1,0,5,1,0,0,1]
,[0,1,0,1,4,0,0,1]
,[1,0,0,0,0,3,1,0]
,[2,0,0,0,0,1,2,0]
,[0,1,0,1,1,0,0,1]]
 */
int main() { return 0; }