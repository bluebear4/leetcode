#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rall(x) x.rbegin(), x.rend()

class Solution {
    class segment_Tree_max {
        class node {
           public:
            int l, r;  //区间[l,r]
            int max;   //区间最大值
        };
        void pushup(int root) {
            tree[root].max = max(tree[root << 1].max, tree[root << 1 | 1].max);
        }

        vector<node> tree;

       public:
        segment_Tree_max(int _n) : tree((_n + 1) << 2){};

        void build(int l, int r, int root = 1) {
            tree[root].l = l;
            tree[root].r = r;
            if (l == r) {
                tree[root].max = 0;
                return;
            }
            int mid = (l + r) >> 1;
            build(l, mid, root << 1);
            build(mid + 1, r, root << 1 | 1);
            pushup(root);
        }

        void update(int l, int r, int val, int root = 1) {
            if (l <= tree[root].l && r >= tree[root].r) {
                tree[root].max = val;
                return;
            }
            int mid = (tree[root].l + tree[root].r) >> 1;
            if (l <= mid) update(l, r, val, root << 1);
            if (r > mid) update(l, r, val, root << 1 | 1);
            pushup(root);
        }

        int query(int l, int r, int root = 1) {
            if (l <= tree[root].l && r >= tree[root].r) {
                return tree[root].max;
            }
            int mid = (tree[root].l + tree[root].r) >> 1;
            int Max = 0;
            if (l <= mid) Max = max(query(l, r, root << 1), Max);
            if (r > mid) Max = max(query(l, r, root << 1 | 1), Max);
            return Max;
        }
    };

   public:
    int lengthOfLIS(vector<int>& nums, int k) {
        segment_Tree_max T(200010);
        T.build(1, 200010);
        int ans = 0;
        for (auto& it : nums) {
            int val = T.query(it - k, it - 1) + 1;
            ans = max(ans, val);
            T.update(it, it, val);
        }
        return ans;
    }
};
int main() {
    vector<int> a{4, 2, 1, 4, 3, 4, 5, 8, 15};
    Solution().lengthOfLIS(a, 3);
    return 0;
}