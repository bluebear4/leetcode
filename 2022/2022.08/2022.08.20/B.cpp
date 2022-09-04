#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int secondsToRemoveOccurrences(string s) {
        int ans = 0;
        while (1) {
            bool ret = true;
            for (int i = 0; i + 1 < s.length(); ++i) {
                if (s[i] == '0' && s[i + 1] == '1') {
                    s[i] = '1';
                    s[i + 1] = '0';
                    ++i;
                    ret = false;
                }
            }
            if(ret) return ans;
            ++ans;
        }
        return -1;
    }
};
int main(){
    //Solution()
    return 0;
}