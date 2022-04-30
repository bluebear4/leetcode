#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> cnt;
        for (auto& task : tasks) {
            cnt[task]++;
        }
        int ans = 0;
        for (auto& [u, v] : cnt) {
            if (v == 1) return -1;
            int three = v / 3, two = 0;
            v %= 3;
            switch (v % 3) {
                case 0:
                    break;
                case 1:
                    if (three == 0) return -1;
                    --three;
                    two += 2;
                    break;
                case 2:
                    ++two;
                    break;
            }
            ans += three + two;
        }
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}