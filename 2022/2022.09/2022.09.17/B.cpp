#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rall(x) x.rbegin(), x.rend()
class Solution {
#define all(x) x.begin(), x.end()
   public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(all(players));
        sort(all(trainers));
        int i = 0, j = 0, ans = 0;
        while (i < players.size() && j < trainers.size()) {
            if (players[i] <= trainers[j]) {
                ++ans;
                ++i;
                ++j;
            } else {
                ++j;
            }
        }
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}