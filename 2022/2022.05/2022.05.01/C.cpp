#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int countDistinct(vector<int>& nums, int maxx, int p) {
        unordered_map<int, set<vector<int>>> cnt;
        int n = nums.size();
        vector<int> sum(n, 0);
        for (int i = 0; i < n; ++i) {
            if (i) sum[i] = sum[i - 1];
            sum[i] += (nums[i] % p == 0);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (i && sum[j] - sum[i - 1] <= maxx) {
                    vector<int> temp;
                    for (int k = i; k <= j; ++k) {
                        temp.emplace_back(nums[k]);
                    }
                    cnt[temp.size()].insert(temp);
                }
                if (i == 0 && sum[j] <= maxx) {
                    vector<int> temp;
                    for (int k = i; k <= j; ++k) {
                        temp.emplace_back(nums[k]);
                    }
                    cnt[temp.size()].insert(temp);
                }
            }
        }
        int ans = 0;
        for (auto& [k, v] : cnt) {
            ans += v.size();
        }
        return ans;
    }
};
int main() {
    vector<int> a{2, 3, 3, 2, 2};
    Solution().countDistinct(a, 2, 2);
    return 0;
}