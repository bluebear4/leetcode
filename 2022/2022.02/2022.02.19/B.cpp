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
    vector<long long> sumOfThree(long long num) {
        if (num % 3 != 0) {
            return vector<long long>{};
        }
        return vector<long long>{num / 3 - 1, num / 3, num / 3 + 1};
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    return 0;
}