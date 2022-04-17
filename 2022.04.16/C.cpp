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

class Solution {
    using pii = pair<int, int>;
    void dfs(TreeNode* root, vector<int>& vals) {
        if (root == nullptr) return;
        vals.emplace_back(root->val);
        dfs(root->left, vals);
        dfs(root->right, vals);
    }

   public:
    int getNumber(TreeNode* root, vector<vector<int>>& ops) {
        vector<int> vals;
        dfs(root, vals);
        sort(vals.begin(), vals.end());
        int n = vals.size();
        vector<vector<pii>> color(n + 1, vector<pii>());
        for (int i = 0; i < ops.size(); ++i) {
            int l = ops[i][1];
            int r = ops[i][2];

            int lpos = lower_bound(vals.begin(), vals.end(), l) - vals.begin();
            int rpos = lower_bound(vals.begin(), vals.end(), r) - vals.begin();
            printf("%d(pos:%d)-%d(pos:%d),color:%d", l, lpos, r, rpos,
                   ops[i][0] + 1);
            color[lpos].emplace_back(i, ops[i][0] + 1);
            color[rpos + 1].emplace_back(i, -ops[i][0] - 1);
        }
        int ans = 0;
        map<int, int> now;
        for (int i = 0; i < vals.size(); ++i) {
            for (auto& it : color[i]) {
                cout << "now is " << i << " and " << it.first << "/"
                     << it.second << endl;
                if (it.second > 0) {
                    now[it.first] = it.second;
                } else {
                    now.erase(it.first);
                }
            }
            if (now.size() && now.rbegin()->second == 2) {
                ++ans;
            }
        }
        return ans;
    }
};

int main() {
    // Solution()
    return 0;
}