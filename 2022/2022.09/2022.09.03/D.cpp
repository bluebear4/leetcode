#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rall(x) x.rbegin(), x.rend()
class Solution {
#define all(x) x.begin(), x.end()
   public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts,
                      long long budget) {
        int n = chargeTimes.size();

        multiset<long long, greater<int>> maxx;

        long long l = 0, r = 0, ans = 0, sum = 0;
        while (l <= r && r < n) {
            maxx.insert(chargeTimes[r]);
            sum += runningCosts[r];
            ++r;

            while (maxx.size() && *maxx.begin() + (r - l) * sum > budget) {
                sum -= runningCosts[l];
                maxx.erase(maxx.find(chargeTimes[l]));
                ++l;
            }
            ans = max(ans, r - l);
        }

        return ans;
    }
};
int main() {
    vector<int> a{11, 12, 74, 67, 37, 87, 42, 34, 18, 90, 36, 28, 34, 20};
    vector<int> b{18, 98, 2, 84, 7, 57, 54, 65, 59, 91, 7, 23, 94, 20};
    Solution().maximumRobots(a, b, 937);
    return 0;
}