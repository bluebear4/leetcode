#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        sort(basket1.begin(), basket1.end());
        sort(basket2.begin(), basket2.end());

        unordered_map<long long, long long> cnt;
        for (auto& it : basket1) cnt[it]++;
        for (auto& it : basket2) cnt[it]++;
        for (auto& [k, v] : cnt) {
            if (v & 1) return -1;
        }

        map<long long, long long> cnt1;
        for (auto& it : basket1) cnt1[it]++;
        map<long long, long long> cnt2;
        for (auto& it : basket2) cnt2[it]++;

        deque<long long> a;
        for (auto& [k, v] : cnt1) {
            for (long long i = 0; i < v - cnt[k] / 2; ++i) {
                a.emplace_back(k);
            }
        }

        deque<long long> b;
        for (auto& [k, v] : cnt2) {
            for (long long i = 0; i < v - cnt[k] / 2; ++i) {
                b.emplace_back(k);
            }
        }
        if (a.size() == 0) return 0;

        long long ans = 0;
        if (min(a[0], b[0]) == min(basket1[0], basket2[0])) {
            if (a[0] <= b[0]) {
                ans += a[0];
                a.pop_front();
                b.pop_back();
            }
        }

        while (a.size()) {
            if (a[0] <= b[0]) {
                if (a[0] > 2ll * min(basket1[0], basket2[0])) {
                    a.pop_back();
                    b.pop_back();
                    ans += 2ll * min(basket1[0], basket2[0]);
                } else {
                    ans += a[0];
                    a.pop_front();
                    b.pop_back();
                }
            }else{
                if (b[0] > 2ll * min(basket1[0], basket2[0])) {
                    a.pop_back();
                    b.pop_back();
                    ans += 2ll * min(basket1[0], basket2[0]);
                } else {
                    ans += b[0];
                    b.pop_front();
                    a.pop_back();
                }
            }
        }

        return ans;
    }
};
int main() {
    vector<int> a{2, 2, 2, 4};
    vector<int> b{1, 4, 1, 2};
    Solution().minCost(a, b);
    return 0;
}