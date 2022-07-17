#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rall(x) x.rbegin(), x.rend()
class Solution {
#define all(x) x.begin(), x.end()
   public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers,
                              int capacity) {
        sort(all(buses));
        sort(all(passengers));

        auto check = [&](int x) {
            int index = 0, now;
            for (int i = 0; i < buses.size(); ++i) {
                now = 0;
                while (now < capacity && index < passengers.size()) {
                    if (x <= passengers[index]) {
                        if (x <= buses[i]) {
                            return true;
                        } else {
                            break;
                        }
                    } else if (passengers[index] <= buses[i]) {
                        ++now;
                        ++index;
                    } else {
                        break;
                    }
                }
            }
            if (now < capacity) return x <= buses.back();
            return false;
        };

        int l = 0, r = 1000000000, mid, ans;
        while (l <= r) {
            mid = (l + r) / 2;
            if (check(mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        int it = find(all(passengers), ans) - passengers.begin();
        while (it != passengers.size() && it >= 0 && passengers[it] == ans) {
            ans = passengers[it--] - 1;
        }
        return ans;
    }
};
int main() {
    vector<int> a{3};
    vector<int> b{4};
    Solution().latestTimeCatchTheBus(a, b, 1);
    return 0;
}