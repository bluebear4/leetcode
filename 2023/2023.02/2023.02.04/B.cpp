#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> ban(banned.begin(), banned.end());
        int now = 0;
        for (int i = 1, sum = 0; i <= n; ++i) {
            if (ban.count(i)) continue;
            if (sum + i > maxSum) return now;
            now++;
            sum += i;
        }
        return now;
    }
};
int main() { return 0; }