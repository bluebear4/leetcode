#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int Leetcode(vector<string>& words) {
        vector<int> dp(1 << 13, INT_MAX / 2);
        //已有 当前 的状压
        //ab
        //a
        //cabd
        dp[0] = 0;
        for (auto& word : words) {
            vector<int> temp(1 << 13);
            for (int i = 0; i < (1 << 13); ++i) {
                int l = 0, r = word.length() - 1;
                while(l<=r){
                    
                }
            }
        }
    }
};
int main() {
    // Solution()
    return 0;
}