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
    bool evaluateTree(TreeNode *root) {
        if (root == nullptr) return false;
        if (root->val == 2) {
            return evaluateTree(root->left) || evaluateTree(root->right);
        } else if (root->val == 3) {
            return evaluateTree(root->left) && evaluateTree(root->right);
        }
        return root->val;
    }
};
int main() {
    // Solution()
    return 0;
}