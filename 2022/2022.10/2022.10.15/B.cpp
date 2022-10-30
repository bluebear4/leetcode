#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
    using ll = long long;
    static constexpr ll mod = 1e9 + 7;
    ll ksm(ll a, ll n = mod - 2, ll m = mod) {
        ll ans = 1;
        a %= m;
        while (n) {
            if (n & 1) ans = ans * a % m;
            a = a * a % m;
            n >>= 1;
        }
        return ans;
    }

   public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<ll> bits;
        for (int i = 0; i < 31; ++i) {
            if (1 << i & n) {
                bits.push_back(1 << i);
            }
        }
        for (int i = 1; i < bits.size(); ++i) {
            bits[i] = bits[i - 1] * bits[i] % mod;
        }
        vector<int> ans;
        for (auto& querie : queries) {
            if (querie[0] == 0) {
                ans.push_back(bits[querie[1]]);
            } else {
                ans.push_back(bits[querie[1]] * ksm(bits[querie[0] - 1]) % mod);
            }
        }
        return ans;
    }
};
int main(){
    //Solution()
    return 0;
}