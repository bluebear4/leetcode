#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rall(x) x.rbegin(), x.rend()

class Solution {
    typedef pair<long long, int> pli;

   public:
    long long kSum(vector<int>& A, int K) {
        int n = A.size();
        // sm 表示所有数的和，neg 表示所有负数之和
        long long sm = 0, neg = 0;
        for (int i = 0; i < n; i++) {
            sm += A[i];
            if (A[i] < 0) neg += A[i], A[i] = -A[i];
        }
        sort(A.begin(), A.end());

        // k = 1 时的答案，也就是空集的和
        long long ans = 0;
        priority_queue<pli, vector<pli>, greater<pli>> pq;
        pq.push(pli(A[0], 0));
        for (int i = 2; i <= K; i++) {
            pli p = pq.top();
            pq.pop();
            // k = i 时的答案
            ans = p.first;
            if (p.second == n - 1) continue;
            pq.push(pli(p.first + A[p.second + 1], p.second + 1));
            pq.push(pli(p.first - A[p.second] + A[p.second + 1], p.second + 1));
        }
        return sm - (neg + ans);
    }
};

// 作者：TsReaper
// 链接：https://leetcode.cn/circle/discuss/t6hE2C/view/MwcHdY/
// https://leetcode.cn/circle/discuss/t6hE2C/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
int main() {
    vector<int> a{1000, 1001, 1002, 1003, 1004, 1005, 1006, 1007, 1008, 1009};
    Solution().kSum(a, 10);
    return 0;
}