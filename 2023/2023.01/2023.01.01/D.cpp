#include <bits/stdc++.h>
using namespace std;
class Solution {
    class Euler_sieve {
        vector<int> vis;

       public:
        vector<int> prime;
        Euler_sieve(int _n) : vis(_n + 1) {
            for (int i = 2; i <= _n; ++i) {
                if (!vis[i]) prime.emplace_back(i);
                for (int j = 0; j < prime.size(); ++j) {
                    if (1ll * i * prime[j] > _n) break;
                    vis[i * prime[j]] = true;
                    if (i % prime[j] == 0) break;
                }
            }
        };
        int &operator[](int index) { return prime[index - 1]; }
        bool friend operator==(const Euler_sieve &t, int num) {
            return !t.vis[num];
        }
        bool friend operator==(int num, const Euler_sieve &t) {
            return !t.vis[num];
        }
    };

   public:
    vector<int> closestPrimes(int left, int right) {
        Euler_sieve p{static_cast<int>(right * 1.2)};

        vector<int> ans{-1, -1};
        
        auto start = lower_bound(p.prime.begin(), p.prime.end(), left);
        if(start==p.prime.end()) return ans;
        while (start + 1 < p.prime.end() && *(start + 1) <= right) {
            if (ans[0] == -1) {
                ans[0] = *start;
                ans[1] = *(start + 1);
            } else if (*(start + 1) - *start < ans[1] - ans[0]) {
                ans[0] = *start;
                ans[1] = *(start + 1);
            }
            ++start;
        }
        return ans;
    }
};
int main() {
    Solution().closestPrimes(1, 1);
    return 0;
}