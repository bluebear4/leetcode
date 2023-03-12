#include <bits/stdc++.h>
using namespace std;
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
    void dfs(TreeNode *root, int level, unordered_map<int, long long> &levels) {
        if (root == nullptr) return;
        levels[level] += root->val;
        dfs(root->left, level + 1, levels);
        dfs(root->right, level + 1, levels);
    }

   public:
    long long kthLargestLevelSum(TreeNode *root, int k) {
        unordered_map<int, long long> levels;
        dfs(root,0,levels);
        vector<long long> values;
        for (auto &[k, v] : levels) values.emplace_back(v);
        --k;
        if (values.size() < k) return -1;
        nth_element(values.begin(), values.begin() + k, values.end(),greater<long long>());
        return values[k];
    }
};
int main() { return 0; }