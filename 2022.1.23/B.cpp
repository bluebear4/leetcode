#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int maxn = 3e5 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> a,b;
        for(auto &it:nums){
            if(it>0){
                a.emplace_back(it);
            }else{
                b.emplace_back(it);
            }
        }
        vector<int> ans;
        for(int i=0;i<a.size();++i){
            ans.emplace_back(a[i]);
            ans.emplace_back(b[i]);
        }
        return ans;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    return 0;
}