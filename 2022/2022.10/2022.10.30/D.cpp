#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
    //子树高度
    int dfs(TreeNode *root, unordered_map<int, pair<int, int>> &dep) {
        if (root == nullptr) return 0;
        return dep[root->val].first =
                   max(dfs(root->left, dep), dfs(root->right, dep)) + 1;
    }

    // root深度
    void dfs(TreeNode *root, int now, unordered_map<int, pair<int, int>> &dep) {
        if (root == nullptr) return;
        dep[root->val].second = now;
        dfs(root->left, now + 1, dep);
        dfs(root->right, now + 1, dep);
        return;
    }

   public:
    vector<int> treeQueries(TreeNode *root, vector<int> &queries) {
        unordered_map<int, pair<int, int>> dep;
        int ans = dfs(root, dep) - 1;
        dfs(root, 0, dep);

        unordered_map<int, vector<int>> dep_rating;
        for (auto &[k, v] : dep) {
            dep_rating[v.second].emplace_back(k);
        }

        for (auto &[k, v] : dep_rating) {
            sort(v.begin(), v.end(),
                 [&dep](int x, int y) { return dep[x] > dep[y]; });
        }

        vector<int> ret;
        for (auto &q : queries) {
            if (dep_rating[dep[q].second][0] != q) {
                ret.emplace_back(ans);
            } else {
                if (dep_rating[dep[q].second].size() == 1) {
                    ret.emplace_back(ans - dep[q].first);
                } else {
                    ret.emplace_back(ans - dep[q].first +
                                     dep[dep_rating[dep[q].second][1]].first);
                }
            }
        }
        return ret;
    }
};
int main() {
    // Solution()
    return 0;
}