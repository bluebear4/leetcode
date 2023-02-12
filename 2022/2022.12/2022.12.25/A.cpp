#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size(), ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (words[i] == target) {
                ans =
                    min(ans, min(abs(i - startIndex), n - abs(i - startIndex)));
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
int main() { return 0; }