#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int maxn = 3e5 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    vector<int> findLonely(vector<int>& nums) {
        map<int, int> cnt;
        vector<int> ans;
        for (auto& it : nums) {
            cnt[it]++;
        }
        for (auto it = cnt.begin(); it != cnt.end(); ++it) {
            if (it->second > 1) {
                continue;
            }

            if (it != cnt.begin()) {
                auto pre = next(it, -1);
                if (pre->first == it->first - 1) continue;
            }

            if (it != --cnt.end()) {
                auto nxt = next(it, 1);
                if (nxt->first - 1 == it->first) continue;
            }
            ans.emplace_back(it->first);
        }
        return ans;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    return 0;
}