#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    bool isCircularSentence(string sentence) {
        if (sentence[0] != sentence.back()) return false;
        int pos = sentence.find(' ', 0);
        while (pos != string::npos) {
            if (sentence[pos - 1] != sentence[pos + 1]) return false;
            pos = sentence.find(' ', pos + 1);
        }
        return true;
    }
};
int main() {
    // Solution()
    return 0;
}