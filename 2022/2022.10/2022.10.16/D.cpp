#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        vector<int> pos{{-1}};
        vector<int> pos_min{-1};
        vector<int> pos_max{-1};
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] < minK || nums[i] > maxK) {
                pos.push_back(i);
            } else {
                if (nums[i] == minK) pos_min.push_back(i);
                if (nums[i] == maxK) pos_max.push_back(i);
            }
        }
        pos.push_back(n);

        long long ans = 0;
        for (int i = 1, j = 1, k = 0;
             i < pos_min.size() && j < pos_max.size() && k + 1 < pos.size();) {
            if (max(pos_min[i], pos_max[j]) > pos[k] &&
                max(pos_min[i], pos_max[j]) < pos[k + 1]) {
                // k i j k+1
                // k j i k+1
                ans +=
                    1ll * (pos[k + 1] - max(pos_min[i], pos_max[j])) *
                    (max(0, min(pos_min[i], pos_max[j]) -
                                max({pos_min[i - 1], pos_max[j - 1], pos[k]})));
                if (pos_min[i] < pos_max[j]) {
                    ++i;
                } else if (pos_min[i] > pos_max[j]) {
                    ++j;
                } else {
                    ++i;
                    ++j;
                }
            } else {
                if (max(pos_min[i], pos_max[j]) > pos[k]) {
                    // k i k+1 j
                    // k j k+1 i
                    ++k;
                } else {
                    // i k j
                    // j k i
                    if (pos_min[i] < pos_max[j]) {
                        ++i;
                    } else if (pos_min[i] > pos_max[j]) {
                        ++j;
                    } else {
                        ++i;
                        ++j;
                    }
                }
            }
        }
        return ans;
    }
};
int main() {
    vector<int> a{1, 2, 3, 3, 2, 3, 1, 3, 2, 3, 1, 2, 2, 2, 2};
    Solution().countSubarrays(a, 1, 3);
    return 0;
}