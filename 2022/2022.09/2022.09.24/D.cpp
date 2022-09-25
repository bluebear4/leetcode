#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 0：全关 1：全开 2：子关我开 3：子开我关
class Solution {
    int dfs(TreeNode* root, int way, vector<vector<int>>& dp) {
        if (root == nullptr) return 0;

        if (dp[abs(root->val)][way] != -1) return dp[abs(root->val)][way];

        int l0 = dfs(root->left, 0, dp);
        int l1 = dfs(root->left, 1, dp);
        int l2 = dfs(root->left, 2, dp);
        int l3 = dfs(root->left, 3, dp);

        int r0 = dfs(root->right, 0, dp);
        int r1 = dfs(root->right, 1, dp);
        int r2 = dfs(root->right, 2, dp);
        int r3 = dfs(root->right, 3, dp);

        switch (way) {
            case 0:
                return dp[abs(root->val)][way] =
                           min({l0 + r0 + (root->val > 0),
                                l1 + r1 + (root->val < 0) + 1,
                                l2 + r2 + (root->val < 0) + 1,
                                l3 + r3 + (root->val > 0) + 2});
            case 1:
                return dp[abs(root->val)][way] =
                           min({l0 + r0 + (root->val > 0) + 1,
                                l1 + r1 + (root->val < 0),
                                l2 + r2 + (root->val < 0) + 2,
                                l3 + r3 + (root->val > 0) + 1});
            case 2:
                return dp[abs(root->val)][way] =
                           min({l0 + r0 + (root->val < 0),
                                l1 + r1 + (root->val > 0) + 1,
                                l2 + r2 + (root->val > 0) + 1,
                                l3 + r3 + (root->val < 0) + 2});
                // 0：全关 1：全开 2：子关我开 3：子开我关

            case 3:
                return dp[abs(root->val)][way] =
                           min({l0 + r0 + (root->val < 0) + 1,
                                l1 + r1 + (root->val > 0),
                                l2 + r2 + (root->val > 0) + 2,
                                l3 + r3 + (root->val < 0) + 1});

            default:
                return -1;
        }
        return -1;
    }
    void dfs(TreeNode* root, int& cnt) {
        if (root == nullptr) return;
        if (root->val) {
            root->val = cnt;
        } else {
            root->val = -cnt;
        }
        ++cnt;
        dfs(root->left, cnt);
        ++cnt;
        dfs(root->right, cnt);
    }

   public:
    int closeLampInTree(TreeNode* root) {
        int cnt = 1;
        dfs(root, cnt);
        vector<vector<int>> dp(cnt + 1, vector<int>(4, -1));
        return dfs(root, 0, dp);
    }
};
int main() {
    // Solution()
    return 0;
}