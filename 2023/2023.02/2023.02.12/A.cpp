#include <bits/stdc++.h>
using namespace std;
class Solution {
    long long mix(int x, int y) {
        string s = to_string(x) + to_string(y);
        return stoll(s);
    }

   public:
    long long findTheArrayConcVal(vector<int>& nums) {
        deque<int> a(nums.begin(), nums.end());
        long long ans = 0;
        while (a.size() > 1) {
            ans += mix(a.front(), a.back());
            a.pop_back();
            a.pop_front();
        }
        if(a.size()==1){
            return ans + a[0];
        }
        return ans;
    }
};
int main() { return 0; }