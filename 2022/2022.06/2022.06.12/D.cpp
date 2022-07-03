#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    long long distinctNames(vector<string>& ideas) {
        struct node {
            int a[26] = {0};
            node& operator+=(int x) {
                a[x - 'a']++;
                return *this;
            }
            node& operator+=(const node& x) {
                for (int i = 0; i < 26; ++i) {
                    a[i] += x.a[i];
                }
                return *this;
            }
            node& operator-=(node& x) {
                for (int i = 0; i < 26; ++i) {
                    a[i] -= x.a[i];
                }
                return *this;
            }
            long long operator*(node& x) {
                long long r = 0;
                for (int i = 0; i < 26; ++i) {
                    if (a[i] == 0) r += x.a[i];
                }
                return r;
            }
        };
        unordered_map<string, node> suff;
        for (auto& it : ideas) {
            suff[it.substr(1)] += it[0];
        }
        node all[26];
        for (int i = 0; i < 26; ++i) {
            for (auto& [k, v] : suff) {
                if (v.a[i] == 0) all[i] += v;
            }
        }
        long long ans = 0;
        for (auto& idea : ideas) {
            ans += suff[idea.substr(1)] * all[idea[0] - 'a'];
        }
        return ans;
    }
};
int main() {
    vector<string> a{"coffee", "donuts", "time", "toffee"};
    Solution().distinctNames(a);
    return 0;
}