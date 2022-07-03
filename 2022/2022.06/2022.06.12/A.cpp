#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double ans = 0;
        brackets.insert(brackets.begin(), vector<int>{0, 0});
        for (int i = 1; i < brackets.size(); ++i) {
            ans += 1.0 * (min(income, brackets[i][0]) - brackets[i - 1][0]) *
                   brackets[i][1] / 100;
            if (income < brackets[i][0]) break;
        }
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}