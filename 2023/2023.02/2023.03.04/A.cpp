#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int splitNum(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end());
        int a = 0, b = 0, index = 0;
        while (index < s.length()) {
            a = a * 10 + s[index++] - '0';
            if (index == s.length()) break;
            b = b * 10 + s[index++] - '0';
        }
        return a+b;
    }
};
int main() { return 0; }