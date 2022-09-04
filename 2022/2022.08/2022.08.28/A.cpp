#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rall(x) x.rbegin(), x.rend()
class Solution {
#define all(x) x.begin(), x.end()
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(all(nums));
        vector<long long>sum(all(nums));
        for(int i=1;i<sum.size();++i){
            sum[i]+=sum[i-1];
        }
        vector<int> ans;
        for(auto &q:queries){
            ans.emplace_back(upper_bound(all(sum),q)-sum.begin());
        }
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}