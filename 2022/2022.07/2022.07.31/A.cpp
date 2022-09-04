#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rall(x) x.rbegin(), x.rend()
class Solution {
#define all(x) x.begin(),x.end()
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> a(all(nums));
        a.erase(0);
        return a.size();
    }
};
int main(){
    //Solution()
    return 0;
}