#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
    void dfs(const vector<vector<int>>& G, int now, vector<int>& fa) {
        for (auto& son : G[now]) {
            if (fa[now] == son) continue;
            fa[son] = now;
            dfs(G, son, fa);
        }
    }

   public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob,
                           vector<int>& amount) {
        int n = amount.size();

        vector<vector<int>> G(n, vector<int>());
        for (auto& it : edges) {
            G[it[0]].emplace_back(it[1]);
            G[it[1]].emplace_back(it[0]);
        }

        vector<int> fa(n, -1);
        dfs(G, 0, fa);

        // pos point
        queue<pair<int, int>> q;
        q.emplace(0, 0);

        unordered_set<int> B;

        int ans = INT_MIN;
        while (q.size()) {
            int sz = q.size();
            while (sz--) {
                auto [now, point] = q.front();
                q.pop();

                if (G[now].size() == 1 && now != 0) {
                    if (B.count(now)) {  // B走过了
                        ans = max(ans, point);
                    } else if (bob == now) {  // 碰面
                        ans = max(ans, point + amount[now] / 2);
                    } else {  //独占
                        ans = max(ans, point + amount[now]);
                    }
                    continue;
                }

                for (auto& son : G[now]) {
                    if (son == fa[now]) continue;
                    if (B.count(now)) {  // B走过了
                        q.emplace(son, point);
                    } else if (bob == now) {  // 碰面
                        q.emplace(son, point + amount[now] / 2);
                    } else {  //独占
                        q.emplace(son, point + amount[now]);
                    }
                }
            }
            if (bob != -1) {
                B.insert(bob);
                bob = fa[bob];
            }
        }

        return ans;
    }
};
int main() {
    vector<vector<int>> G{
        {0, 38},  {0, 59},  {1, 30},  {1, 62},  {1, 53},  {2, 41},  {2, 37},
        {3, 21},  {4, 35},  {4, 54},  {5, 32},  {5, 69},  {6, 26},  {6, 16},
        {6, 61},  {6, 52},  {7, 34},  {8, 10},  {9, 11},  {9, 43},  {10, 48},
        {11, 29}, {12, 63}, {12, 58}, {12, 13}, {13, 36}, {13, 34}, {14, 65},
        {14, 15}, {15, 17}, {15, 49}, {16, 40}, {17, 20}, {17, 24}, {18, 58},
        {19, 25}, {21, 34}, {22, 55}, {23, 45}, {23, 59}, {25, 43}, {27, 32},
        {28, 49}, {28, 33}, {31, 61}, {33, 39}, {33, 51}, {33, 53}, {34, 68},
        {34, 69}, {37, 52}, {42, 52}, {43, 61}, {44, 58}, {46, 49}, {47, 55},
        {47, 50}, {48, 56}, {48, 66}, {50, 58}, {52, 66}, {52, 65}, {53, 57},
        {54, 63}, {55, 57}, {59, 60}, {59, 67}, {59, 65}, {64, 69}};
    vector<int> a{4664,  5822,  -9152, 7258,  -5468, 4698,  2568,  9880,  -4046,
                  9884,  -3540, -2260, 5264,  -7050, -6998, -1688, -6256, -5350,
                  5136,  7476,  -4108, 1288,  1336,  -6126, 2940,  698,   -2900,
                  -2342, -2310, 858,   572,   640,   -9674, 5746,  5068,  7128,
                  636,   6680,  -1840, 3574,  7592,  -5882, -1974, -2766, -620,
                  1088,  -8930, 7756,  9966,  380,   8884,  -954,  -8198, -5862,
                  -3100, 7728,  7090,  -4648, 4076,  994,   4232,  9810,  -2904,
                  -1106, -4172, -5884, -9582, 5320,  -4086, 6346};
    Solution().mostProfitablePath(G, 47, a);
    return 0;
}