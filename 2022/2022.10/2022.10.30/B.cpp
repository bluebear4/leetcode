#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
    struct node {
        string name;
        long long sum;
        vector<pair<string, int>> videos;
    };

   public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators,
                                              vector<string>& ids,
                                              vector<int>& views) {
        unordered_map<string, node> v;
        for (int i = 0; i < ids.size(); ++i) {
            v[creators[i]].name = creators[i];
            v[creators[i]].sum += views[i];
            v[creators[i]].videos.emplace_back(ids[i], views[i]);
        }

        vector<node> nodes;
        for (auto& [k, n] : v) {
            nodes.emplace_back(n);
        }

        sort(nodes.begin(), nodes.end(),
             [](const node& l, const node& r) { return l.sum > r.sum; });

        long long maxx = nodes[0].sum;
        vector<vector<string>> ans;
        for (int i = 0; i < nodes.size() && nodes[i].sum == maxx; ++i) {
            sort(nodes[i].videos.begin(), nodes[i].videos.end(),
                 [](const pair<string, int> l, const pair<string, int> r) {
                     if (l.second != r.second) return l.second > r.second;
                     return l.first < r.first;
                 });
            ans.emplace_back(
                vector<string>{nodes[i].name, nodes[i].videos[0].first});
        }
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}