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
    TreeNode *createBinaryTree(vector<vector<int>> &descriptions) {
        unordered_map<int, int> in;
        unordered_map<int, TreeNode *> nodes;
        for (auto &vec : descriptions) {
            in[vec[1]]++;
            TreeNode *&p = nodes[vec[0]];
            TreeNode *&son = nodes[vec[1]];
            if (p == nullptr) p = new TreeNode(vec[0]);
            if (son == nullptr) son = new TreeNode(vec[1]);
            if (vec[2]) {
                p->left = son;
            } else {
                p->right = son;
            }
        }
        for (auto &node : nodes) {
            if (!in[node.first]) return node.second;
        }
        return nullptr;
    }
};
int main() {
    // Solution()
    return 0;
}