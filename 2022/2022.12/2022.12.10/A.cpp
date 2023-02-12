#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
    static int get_value(const string& s) {
        if (find_if(s.begin(), s.end(), [](int x) { return !isdigit(x); }) ==
            s.end()) {
            return stoi(s);
        } else {
            return s.length();
        }
    }

   public:
    int maximumValue(vector<string>& strs) {
        return get_value(*max_element(strs.begin(), strs.end(),
                                      [](const string& l, const string& r) {
                                          return get_value(l) < get_value(r);
                                      }));
    }
};
int main() {
    // Solution()
    return 0;
}