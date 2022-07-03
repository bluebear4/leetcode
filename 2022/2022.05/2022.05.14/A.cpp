#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int ans = 0;
        for (int i = 0; i + k <= s.length(); ++i) {
            int n = stoi(s.substr(i, k));
            ans += n && (num % n) == 0;
        }
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}