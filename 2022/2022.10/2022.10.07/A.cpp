#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int minNumBooths(vector<string> &demand) {
        unordered_map<int, int> ans, temp;
        for (auto &d : demand) {
            temp.clear();
            for (auto &it : d) temp[it]++;
            for (auto &it : temp) {
                ans[it.first] = max(ans[it.first], it.second);
            }
        }
        int sum = 0;
        for (auto &it : ans) sum += it.second;
        return sum;
    }
};
int main() {
    // Solution()
    return 0;
}