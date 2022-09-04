#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<int> vis;
        for(auto &it:s){
            if(vis.count(it))return it;
            vis.insert(it);
        }
        return -1;
    }
};
int main(){
    //Solution()
    return 0;
}