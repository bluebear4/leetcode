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
    void dfs(TreeNode *root, unordered_map<int, vector<int>> &edges) {
        if (root == nullptr) return;
        if (root->left != nullptr) {
            edges[root->val].emplace_back(root->left->val);
            edges[root->left->val].emplace_back(root->val);
            dfs(root->left, edges);
        }
        if (root->right != nullptr) {
            edges[root->val].emplace_back(root->right->val);
            edges[root->right->val].emplace_back(root->val);
            dfs(root->right, edges);
        }
    }

   public:
    int amountOfTime(TreeNode *root, int start) {
        unordered_map<int, vector<int>> edges;
        dfs(root, edges);
        unordered_set<int> vis;
        queue<int> q;
        q.push(start);
        int ans = -1;
        while (q.size()) {
            int sz = q.size();
            ++ans;
            for (int i = 0; i < sz; ++i) {
                int now = q.front();
                q.pop();
                if (vis.count(now)) continue;
                vis.insert(now);
                for (auto &it : edges[now]) {
                    if (!vis.count(it)) q.push(it);
                }
            }
        }
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}