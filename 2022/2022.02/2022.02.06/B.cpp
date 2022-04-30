#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    long long smallestNumber(long long num) {
        if (num == 0) return num;
        if (num > 0) {
            string s = to_string(num);
            sort(s.begin(), s.end());
            int pos = s.find_first_not_of('0',0);
            swap(s[pos],s[0]);
            return stoll(s);
        } else {
            string s = to_string(-num);
            sort(s.begin(), s.end(), greater<int>());
            return -stoll(s);
        }
    }
};
int main() {
    // Solution()
    return 0;
}