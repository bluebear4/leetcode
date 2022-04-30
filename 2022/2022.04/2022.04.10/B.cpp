#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
    int add(const string &s) {
        int pos = s.find('+');
        if (pos == 0) return -1;
        return stoi(s.substr(0, pos)) + stoi(s.substr(pos + 1));
    }
    int s2i(const string &s) {
        if (s.length() == 0) return 1;
        return stoi(s);
    }

   public:
    string minimizeResult(string e) {
        int num = add(e);
        string ans = "("s + e + ")"s;
        int pos = e.find('+');
        for (int i = 0; i < pos; ++i) {
            for (int j = pos + 1; j < e.length(); ++j) {
                int mul = s2i(e.substr(0, i)) * s2i(e.substr(j + 1));
                string temp = e.substr(0, i) + "("s + e.substr(i, j - i + 1) +
                              ")"s + e.substr(j + 1);

                if (num > mul * add(e.substr(i, j - i + 1))) {
                    num = mul * add(e.substr(i, j - i + 1));
                    ans = temp;
                }
            }
        }
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}