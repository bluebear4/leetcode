#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int convertTime(string current, string correct) {
        int hh1 = stoi(current.substr(0, 2));
        int mm1 = stoi(current.substr(3, 2));
        int hh2 = stoi(correct.substr(0, 2));
        int mm2 = stoi(correct.substr(3, 2));
        int times = hh2 * 60 + mm2 - (hh1 * 60 + mm1);
        if (times < 0) times += 60 * 24;
        int ans = 0;
        ans += times / 60;
        times %= 60;
        ans += times / 15;
        times %= 15;
        ans += times / 5;
        times %= 5;
        ans += times / 1;
        times %= 1;
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}