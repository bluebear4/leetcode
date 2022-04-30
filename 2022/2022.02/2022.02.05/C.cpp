#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int minCostSetTime(int startAt, int moveCost, int pushCost,
                       int targetSeconds) {
        int m = targetSeconds / 60, s = targetSeconds % 60;
        int ans = INT_MAX;
        auto move = [moveCost, pushCost](int &now, int next, int &cost) {
            if (now != next) {
                now = next;
                cost += moveCost;
            }
            cost += pushCost;
        };
        if (m < 100) {
            if (m > 0) {
                int cost = 0, now = startAt;
                string str = to_string(m);
                for (int i = 0; i < str.length(); ++i) {
                    move(now, str[i] - '0', cost);
                }
                str = to_string(s);
                while (str.length() < 2) str = "0" + str;
                for (int i = 0; i < str.length(); ++i) {
                    move(now, str[i] - '0', cost);
                }
                ans = min(ans, cost);
            } else {
                // m==0
                int cost = 0, now = startAt;
                string str = to_string(s);
                for (int i = 0; i < str.length(); ++i) {
                    move(now, str[i] - '0', cost);
                }
                ans = min(ans, cost);
            }
        }
        if (m > 0 && s + 60 < 100) {
            m--;
            s += 60;

            //借位
            if (m > 0) {
                int cost = 0, now = startAt;
                string str = to_string(m);
                for (int i = 0; i < str.length(); ++i) {
                    move(now, str[i] - '0', cost);
                }
                str = to_string(s);
                while (str.length() < 2) str = "0" + str;
                for (int i = 0; i < str.length(); ++i) {
                    move(now, str[i] - '0', cost);
                }
                ans = min(ans, cost);
            } else {
                // m==0
                int cost = 0, now = startAt;
                string str = to_string(s);
                for (int i = 0; i < str.length(); ++i) {
                    move(now, str[i] - '0', cost);
                }
                ans = min(ans, cost);
            }
        }
        return ans;
    }
};
int main(){
    //Solution()
    return 0;
}