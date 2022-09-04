#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rall(x) x.rbegin(), x.rend()
class Solution {
#define all(x) x.begin(), x.end()
   public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int M = 0, P = 0, G = 0;
        int ans = 0;
        for (int i = 0; i < garbage.size(); ++i) {
            auto& it = garbage[i];
            int temp = 0;
            temp = count(all(it), 'M');
            if (temp != 0) {
                ans += temp;
                M = i;
            }
            temp = count(all(it), 'P');
            if (temp != 0) {
                ans += temp;
                P = i;
            }
            temp = count(all(it), 'G');
            if (temp != 0) {
                ans += temp;
                G = i;
            }
        }
        for (int i = 1; i < travel.size(); ++i) {
            travel[i] += travel[i - 1];
        }
        travel.insert(travel.begin(), 0);
        return ans + travel[M] + travel[P] + travel[G];
    }
};
int main() {
    // Solution()
    return 0;
}