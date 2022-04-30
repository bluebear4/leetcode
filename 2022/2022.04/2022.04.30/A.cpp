#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int countPrefixes(vector<string>& words, string s) {
        return count_if(words.begin(), words.end(), [&s](const string& x) {
            return s.substr(0, x.length()) == x;
        });
    }
};
int main() {
    // Solution()
    return 0;
}