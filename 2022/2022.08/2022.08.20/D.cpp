#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    vector<long long> maximumSegmentSum(vector<int>& nums,
                                        vector<int>& removeQueries) {
        vector<long long> sum(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i) {
            sum[i] += sum[i - 1];
        }

        set<pair<int, int>> seg;
        seg.emplace(0, nums.size() - 1);

        multiset<long long> all_sum;
        all_sum.insert(0);
        all_sum.insert(sum.back());

        vector<long long> ans;
        for (auto& it : removeQueries) {
            auto pos = seg.upper_bound(make_pair(it, INT_MAX));
            --pos;
            auto temp = *pos;
            auto temp_sum = sum[temp.second];
            if (temp.first - 1 >= 0) temp_sum -= sum[temp.first - 1];

            seg.erase(pos);
            all_sum.erase(all_sum.find(temp_sum));

            if (temp.first <= it - 1) {
                seg.emplace(temp.first, it - 1);

                auto temp_sum = sum[it - 1];
                if (temp.first - 1 >= 0) temp_sum -= sum[temp.first - 1];
                all_sum.insert(temp_sum);
            }
            if (it + 1 <= temp.second) {
                seg.emplace(it + 1, temp.second);

                auto temp_sum = sum[temp.second];
                temp_sum -= sum[it];
                all_sum.insert(temp_sum);
            }

            ans.push_back(*all_sum.rbegin());
        }
        return ans;
    }
};
int main() {
    vector<int> a{500, 822, 202, 707, 298, 484, 311, 680, 901, 319, 343, 340};
    vector<int> b{6, 4, 0, 5, 2, 3, 10, 8, 7, 9, 1, 11};
    Solution().maximumSegmentSum(a, b);
    return 0;
}