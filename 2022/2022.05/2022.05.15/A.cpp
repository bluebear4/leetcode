#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rall(x) x.rbegin(), x.rend()
class Solution {
#define all(x) x.begin(), x.end()
   public:
    vector<string> removeAnagrams(vector<string>& words) {
        words.erase(unique(all(words),
                           [](string x, string y) {
                               sort(all(x));
                               sort(all(y));
                               return x == y;
                           }),
                    words.end());
        return words;
    }
};
int main() {
    // Solution()
    return 0;
}