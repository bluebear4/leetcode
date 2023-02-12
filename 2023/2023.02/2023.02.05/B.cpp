#include <bits/stdc++.h>
using namespace std;
class Solution {
    bool isOk(int x) {
        return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
    }

   public:
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> sum(n);
        for (int i = 0; i < n; ++i) {
            if (i) sum[i] += sum[i - 1];
            if (isOk(words[i][0]) && isOk(words[i].back())) {
                sum[i]++;
            }
        }
        int q = queries.size();
        vector<int> ans(q);
        for (int i = 0; i < q; ++i) {
            int l = queries[i][0], r = queries[i][1];
            ans[i] = sum[r] - (l ? sum[l - 1] : 0);
        }
        return ans;
    }
};
int main() { return 0; }