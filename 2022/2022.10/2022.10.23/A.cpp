#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        pair<int, int> a, b, c, d;
        a.first = stoi(event1[0].substr(0, 2));
        a.second = stoi(event1[0].substr(3));
        b.first = stoi(event1[1].substr(0, 2));
        b.second = stoi(event1[1].substr(3));

        c.first = stoi(event2[0].substr(0, 2));
        c.second = stoi(event2[0].substr(3));
        d.first = stoi(event2[1].substr(0, 2));
        d.second = stoi(event2[1].substr(3));

        if (b >= c && b <= d) return true;
        if (d >= a && d <= b) return true;
        return false;
    }
};
int main() {
    // Solution()
    return 0;
}