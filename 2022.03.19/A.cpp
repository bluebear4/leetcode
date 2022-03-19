#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> cnt;
        for(auto &it:nums) cnt[it]++;
        for(auto &[k,v]:cnt){
            if(v&1) return false;
        }
        return true;
    }
};
int main(){
    //Solution()
    return 0;
}