#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int countLatticePoints(vector<vector<int>>& circles) {
        auto isIn = [](const vector<int>& circle, int x, int y) {
            int dis = (circle[0] - x) * (circle[0] - x) +
                      (circle[1] - y) * (circle[1] - y);
            return dis <= circle[2] * circle[2];
        };
        int ans = 0;
        for (int i = 0; i <= 200; ++i) {
            for (int j = 0; j <= 200; ++j) {
                for (auto& circle : circles) {
                    if (isIn(circle, i, j)) {
                        ++ans;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}