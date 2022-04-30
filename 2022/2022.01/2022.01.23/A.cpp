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
    int countElements(vector<int>& nums) {
        int mini = count(nums.begin(), nums.end(),
                         *min_element(nums.begin(), nums.end()));
        int maxx = count(nums.begin(), nums.end(),
                         *max_element(nums.begin(), nums.end()));
        return max<int>(nums.size() - mini - maxx,0);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    return 0;
}