#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int beautifulBouquet(vector<int>& flowers, int cnt) {
        unordered_map<int, int> num;
        int n = flowers.size();
        long long ans = 0, mod = 1e9 + 7;
        for (int i = 0, j = 0; j < n; ++j) {
            num[flowers[j]]++;
            while (num[flowers[j]] > cnt) {
                num[flowers[i++]]--;
            }
            ans += j - i + 1;
            ans %= mod;
        }
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}