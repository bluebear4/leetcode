#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int countCollisions(string directions) {
        while (directions.length() && directions.back() == 'R')
            directions.pop_back();
        reverse(directions.begin(), directions.end());
        while (directions.length() && directions.back() == 'L')
            directions.pop_back();
        return count_if(directions.begin(), directions.end(),
                        [](int x) { return x == 'L' || x == 'R'; });
    }
};
int main() {
    // Solution()
    return 0;
}