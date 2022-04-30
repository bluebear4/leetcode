#include <bits/stdc++.h>
using namespace std;
//想歪了 以为是贪心
class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        int m = batteries.size();
        sort(batteries.begin(), batteries.end());
        vector<long long> pre(m + 1);
        for (int i = 0; i < m; ++i)
            pre[i + 1] = pre[i] + batteries[i];
        
        auto check = [&](long long mid) {
            int k = upper_bound(batteries.begin(), batteries.end(), mid) - batteries.begin();
            return pre[k] + mid * (m - k) >= mid * n; 
        };
        
        long long lo = 0, hi = pre[m] / n;
        while (lo <= hi) {
            long long mid = (lo + hi) >> 1;
            if (check(mid))
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        
        return hi;
    }
};
// 作者：吴自华
// 链接：https://leetcode-cn.com/circle/discuss/iozPw7/view/uWThqh/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    return 0;
}