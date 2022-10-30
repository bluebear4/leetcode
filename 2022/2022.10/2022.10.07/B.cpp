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
   public:
    TreeNode *expandBinaryTree(TreeNode *root) {
        if (root == nullptr) return nullptr;
        if (root->left != nullptr) {
            root->left = new TreeNode(-1, root->left, nullptr);
            expandBinaryTree(root->left->left);
        }
        if (root->right != nullptr) {
            root->right = new TreeNode(-1, nullptr, root->right);
            expandBinaryTree(root->right->right);
        }
        return root;
    }
};
int main() {
    // Solution()
    return 0;
}