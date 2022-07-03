#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rall(x) x.rbegin(), x.rend()
class Solution {
#define all(x) x.begin(), x.end()
   public:
    string discountPrices(string sentence, int discount) {
        stringstream ss(sentence);
        string ans, temp;
        char buff[100];
        while (ss >> temp) {
            if (temp[0] != '$') {
                ans += temp + ' ';
            } else {
                string t = temp.substr(1);
                int dotcnt = count(all(t), '.');
                int other = count_if(all(t), [](int x) { return !isdigit(x); });
                if (dotcnt == other && other <= 1 && t.size() > 0) {
                    sprintf(buff, "%.2lf",
                            stod(temp.substr(1)) * (100 - discount) / 100);
                    ans += "$"s + string(buff) + " ";
                } else {
                    ans += temp + ' ';
                }
            }
        }
        ans.pop_back();
        return ans;
    }
};
int main() {
    Solution().discountPrices("there are $1 $2 and 5$ candies in the shop", 50);
    return 0;
}