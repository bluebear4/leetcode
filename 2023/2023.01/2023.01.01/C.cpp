#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int minimumPartition(string s, int k) {
        int ans = 1;
        long long now = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] - '0' > k) return -1;
            if (now * 10 + s[i] - '0' > k) {
                ans++;
                now = s[i] - '0';
            } else {
                now = now * 10 + s[i] - '0';
            }
        }
        return ans;
    }
};
int main() { return 0; }