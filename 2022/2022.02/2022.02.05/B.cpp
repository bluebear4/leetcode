#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    vector<int> pivotArray(vector<int> &nums, int pivot) {
        vector<int> l, r;
        int cnt;
        for (auto &it : nums) {
            if (it < pivot) {
                l.emplace_back(it);
            } else if (it == pivot) {
                ++cnt;
            } else {
                r.emplace_back(it);
            }
        }
        while (cnt--) l.emplace_back(pivot);
        for (auto &it : r) l.emplace_back(it);
        return l;
    }
};
int main(){
    //Solution()
    return 0;
}