#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int distMoney(int money, int children) {
        if (money < children) return -1;
        money -= children;
        vector<int> c(children, 1);
        int ans = 0;
        for (int i = 0; i < children; ++i) {
            if (i + 1 == children) {
                c[i] += money;
                break;
            }
            if (money >= 7) {
                money -= 7;
                c[i] += 7;
            } else {
                if (i + 1 < children) {
                    money--;
                    c[i]++;
                } else {
                    c[i] += money;
                    money = 0;
                }
            }
        }
        if (c.back() == 4) {
            c.back()--;
            c[children - 2]++;
        }
        return count(c.begin(), c.end(), 8);
        //
    }
};
int main() { return 0; }