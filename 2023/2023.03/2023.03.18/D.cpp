#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    long long repairCars(vector<int>& ranks, int cars) {
        auto check = [&ranks, cars](long long x) mutable {
            int remain = cars;
            for (auto& r : ranks) {
                remain -= floor(sqrt(x / r + 0.5));
                if (remain <= 0) return true;
            }
            return remain <= 0;
        };
        long long l = 1, r = 1e18, mid, ans;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (check(mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
int main() {
    vector<int> a{1, 2, 3, 4};
    Solution().repairCars(a, 10);
    return 0;
}