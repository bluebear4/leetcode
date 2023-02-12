#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
// 0
// - 1
//     -3
//     -4
// - 2
class Solution {
    int dfs(int now, int last, int seats, vector<vector<int>> &edges,
            long long &ans) {
        int sum = 1;
        for (auto &son : edges[now]) {
            if (son == last) continue;
            int cnt = dfs(son, now, seats, edges, ans);
            ans += (cnt + seats - 1) / seats;
            sum += cnt;
        }
        return sum;
    }

   public:
    long long minimumFuelCost(vector<vector<int>> &roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>> edges(n, vector<int>());
        for (auto road : roads) {
            edges[road[0]].emplace_back(road[1]);
            edges[road[1]].emplace_back(road[0]);
        }

        long long ans = 0;
        dfs(0, -1, seats, edges, ans);
        return ans;
    }
};
int main() { return 0; }