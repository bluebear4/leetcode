#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    vector<vector<int>> mergeArrays(vector<vector<int>> &nums1,
                                    vector<vector<int>> &nums2) {
        map<int, int> ids;
        for (auto &it : nums1) ids[it[0]] += it[1];
        for (auto &it : nums2) ids[it[0]] += it[1];
        vector<vector<int>> ans;
        for (auto &[k, v] : ids) {
            ans.push_back(vector<int>{k, v});
        }
        return ans;
    }
};
int main() { return 0; }