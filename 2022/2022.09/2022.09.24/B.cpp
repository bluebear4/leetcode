#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int transportationHub(vector<vector<int>>& path) {
        unordered_map<int, int> in, out;
        unordered_set<int> points;
        for (auto& vec : path) {
            in[vec[1]]++;
            out[vec[0]]++;
            points.insert(vec[0]);
            points.insert(vec[1]);
        }
        for (auto& it : in) {
            if (it.second == points.size() - 1 && out[it.first] == 0) {
                return it.first;
            }
        }
        return -1;
    }
};
int main() {
    // Solution()
    return 0;
}