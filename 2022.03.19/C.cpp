#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
    using ll = long long;

   public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq{nums.begin(), nums.end()};
        ll sum = accumulate(nums.begin(), nums.end(), 0ll);
        long double now = 0;
        int ans = 0;
        while (now * 2 < sum) {
            now += pq.top() / 2;
            pq.push(pq.top() / 2);
            pq.pop();
            ++ans;
        }
        return ans;
    }
};
int main(){
    //Solution()
    return 0;
}