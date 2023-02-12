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
    void dfs(TreeNode *root, set<int> &vis) {
        if (root == nullptr) return;
        vis.insert(root->val);
        dfs(root->left, vis);
        dfs(root->right, vis);
    }

   public:
    vector<vector<int>> closestNodes(TreeNode *root, vector<int> &queries) {
        set<int> s;
        dfs(root, s);
        int n = queries.size();
        vector<vector<int>> ans(n);
        for (int i = 0; i < n; ++i) {
            auto min_pos = s.upper_bound(queries[i]);
            if (min_pos == s.begin()) {
                ans[i].emplace_back(-1);
            } else {
                ans[i].emplace_back(*--min_pos);
            }

            auto max_pos = s.lower_bound(queries[i]);
            if (max_pos == s.end()) {
                ans[i].emplace_back(-1);
            } else {
                ans[i].emplace_back(*max_pos);
            }
        }
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}