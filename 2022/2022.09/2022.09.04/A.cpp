#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<int> pos(26, -1);
        for (int i = 0; i < s.length(); ++i) {
            if (pos[s[i] - 'a'] == -1) {
                pos[s[i] - 'a'] = i;
            } else if (i - pos[s[i] - 'a'] - 1 != distance[s[i] - 'a']) {
                return false;
            }
        }
        return true;
    }
};
int main() {
    // Solution()
    return 0;
}