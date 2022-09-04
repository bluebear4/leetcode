#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
    enum Relation {
        LESS,
        EQUAL,
        MORE,
    };
    int factorial(int n) {
        int fc = 1;
        for (int i = 1; i <= n; ++i) fc *= i;
        return fc;
    }

    int permutation(int n, int m) {
        int perm = factorial(n) / factorial(n - m);
        return perm;
    }
    void dfs(const string &max_num, Relation r, int length,
             unordered_set<int> &used, int &ans) {
        if (length > max_num.length() ||
            (length == max_num.length() && r == MORE))
            return;
        if (r == LESS) {
            for (int i = 0; i <= max_num.length() - length; ++i) {
                ans += permutation(10 - used.size(), i);
            }
            return;
        } else if (r == MORE) {
            for (int i = 0; i <= max_num.length() - length - 1; ++i) {
                ans += permutation(10 - used.size(), i);
            }
            return;
        } else {
            if (length != 0) ++ans;
            for (int i = '0' + (length == 0); i <= '9'; ++i) {
                if (used.count(i)) continue;
                used.insert(i);
                Relation rr = LESS;
                if (i > max_num[length]) {
                    rr = MORE;
                } else if ((i == max_num[length])) {
                    rr = EQUAL;
                }
                dfs(max_num, rr, length + 1, used, ans);
                used.erase(i);
            }
        }
        return;
    }

   public:
    int countSpecialNumbers(int n) {
        string num;
        unordered_set<int> used;
        Relation r = EQUAL;
        int ans = 0;
        dfs(to_string(n), r, 0, used, ans);
        return ans;
    }
};
int main() {
    Solution().countSpecialNumbers(20);
    return 0;
}