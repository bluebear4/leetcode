#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        vector<int> day{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        pair<int, int> a, b, c, d;
        sscanf(arriveAlice.c_str(), "%d-%d", &a.first, &a.second);
        sscanf(leaveAlice.c_str(), "%d-%d", &b.first, &b.second);

        sscanf(arriveBob.c_str(), "%d-%d", &c.first, &c.second);
        sscanf(leaveBob.c_str(), "%d-%d", &d.first, &d.second);

        pair<int, int> now{1, 1};
        int ans = 0;
        while (1) {
            if (now >= a && now <= b && now >= c && now <= d) {
                ++ans;
            }
            if (now.first == 12 && now.second == 31) break;

            if (now.second++ == day[now.first]) {
                now.second = 1;
                now.first++;
            }
        }
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}