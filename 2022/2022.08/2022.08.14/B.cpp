#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rall(x) x.rbegin(), x.rend()
class Solution {
#define all(x) x.begin(), x.end()
   public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> score(n);
        for (int i = 0; i < n; ++i) {
            score[edges[i]] += i;
        }
        return max_element(all(score)) - score.begin();
    }
};
int main() {
    // Solution()
    return 0;
}