#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int maxn = 3e5 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int r = count(nums.begin(), nums.end(), 1);
        int maxx = r;
        for (int i = 0, l = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                ++l;
            } else {
                --r;
            }
            maxx = max(maxx, l + r);
        }
        vector<int> ans;
        r = count(nums.begin(), nums.end(), 1);
        if(l+r==maxx) ans.emplace_back(0);
        for (int i = 0, l = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                ++l;
            } else {
                --r;
            }
            if (l + r == maxx) {
                ans.emplace_back(i + 1);
            }
        }
        return ans;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    return 0;
}