#include <bits/stdc++.h>
using namespace std;
class Solution {
    int f(string s, int x, int y) {
        for (auto &it : s) {
            if (it == x) it = y;
        }
        return stoi(s);
    }

   public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        set<int> x;
        for (int i = '0'; i <= '9'; ++i) {
            for (int j = '0'; j <= '9'; ++j) {
                x.insert(f(s, i, j));
            }
        }
        return *x.rbegin() - *x.begin();
    }
};
int main() { return 0; }