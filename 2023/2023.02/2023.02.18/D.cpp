#include <bits/stdc++.h>
using namespace std;
class Solution {
    class segment_Tree_max {
        class node {
           public:
            int l, r;   // 区间[l,r]
            int lazy;   // 区间的延时标记
            int count;  // 区间最大值
        };
        void pushdown(int root) {
            if (tree[root].lazy & 1) {
                tree[root << 1].count =
                    (tree[root << 1].r - tree[root << 1].l + 1) -
                    tree[root << 1].count;

                tree[root << 1 | 1].count =
                    (tree[root << 1 | 1].r - tree[root << 1 | 1].l + 1) -
                    tree[root << 1 | 1].count;
                tree[root << 1].lazy ^= tree[root].lazy;
                tree[root << 1 | 1].lazy ^= tree[root].lazy;
                tree[root].lazy = 0;
            }
        }
        void pushup(int root) {
            tree[root].count =
                tree[root << 1].count + tree[root << 1 | 1].count;
        }
        int n;
        vector<node> tree;

       public:
        vector<int> array;
        segment_Tree_max(int _n, vector<int> _array)
            : n(_n), tree((_n + 1) << 2), array(_array){};

        void build(int l, int r, int root = 1) {
            tree[root].l = l;
            tree[root].r = r;
            tree[root].lazy = 0;  // 刚开始一定要清0
            if (l == r) {
                tree[root].count = array[l];
                return;
            }
            int mid = (l + r) >> 1;
            build(l, mid, root << 1);
            build(mid + 1, r, root << 1 | 1);
            pushup(root);
        }

        void update(int l, int r, int val = 1, int root = 1) {
            if (l <= tree[root].l && r >= tree[root].r) {
                tree[root].count =
                    (tree[root].r - tree[root].l + 1) - tree[root].count;
                tree[root].lazy ^= val;  // 延时标记
                return;
            }
            pushdown(root);
            int mid = (tree[root].l + tree[root].r) >> 1;
            if (l <= mid) update(l, r, val, root << 1);
            if (r > mid) update(l, r, val, root << 1 | 1);
            pushup(root);
        }

        int query() { return tree[1].count; }
    };

   public:
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2,
                                  vector<vector<int>>& queries) {
        long long sum = accumulate(nums2.begin(), nums2.end(), 0ll);
        nums1.insert(nums1.begin(), 0);
        segment_Tree_max T(nums2.size(), nums1);
        T.build(1, nums2.size());
        vector<long long> ans;
        for (auto& querie : queries) {
            switch (querie[0]) {
                case 1:
                    T.update(querie[1] + 1, querie[2] + 1);
                    break;
                case 2:
                    sum += T.query() * querie[1];
                    break;
                case 3:
                    ans.emplace_back(sum);
                    break;
                default:
                    break;
            }
        }
        return ans;
    }
};
int main() { return 0; }