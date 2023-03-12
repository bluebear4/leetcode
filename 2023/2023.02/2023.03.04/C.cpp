#include <bits/stdc++.h>
using namespace std;
class Solution {
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return {};
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for (int i = 0; i < intervals.size(); ++i) {
            int L = intervals[i][0], R = intervals[i][1];
            if (!merged.size() || merged.back()[1] < L) {
                merged.push_back({L, R});
            } else {
                merged.back()[1] = max(merged.back()[1], R);
            }
        }
        return merged;
    }
    long long ksm(long long a, long long n, long long m = 1e9 + 7) {
        long long ans = 1;
        a %= m;
        while (n) {
            if (n & 1) ans = ans * a % m;
            a = a * a % m;
            n >>= 1;
        }
        return ans;
    }

   public:
    int countWays(vector<vector<int>>& ranges) {
        return ksm(2, merge(ranges).size());
    }
};
int main() {
    vector<int> a{9,  10, 10, 14, 15, 16, 17, 17, 24, 28, 29, 31, 32,
                  40, 42, 48, 51, 55, 64, 68, 71, 83, 98, 99, 99, 100};
    Solution().maxNumOfMarkedIndices(a);
    return 0;
};
