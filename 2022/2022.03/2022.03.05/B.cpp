#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> id;
        for (int i = 0; i < n; ++i) {
            string s = to_string(nums[i]);
            for (auto& ch : s) ch = mapping[ch - '0'] + '0';
            id[nums[i]] = stoi(s);
        }
        stable_sort(nums.begin(), nums.end(),
                    [&](int x, int y) { return id[x] < id[y]; });
        return nums;
    }
};
int main(){
    //Solution()
    return 0;
}