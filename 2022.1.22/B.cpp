#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        vector<long long> a{lower};
        for (int i = 0; i < differences.size(); ++i) {
            a.push_back(a.back() + differences[i]);
        }
        long long mini = *min_element(a.begin(), a.end());
        long long maxx = *max_element(a.begin(), a.end());
        // 1 2 -1 3
        //6-3-2
        //3 4 1 5

        return min(0ll, (upper - maxx) - (lower - mini) + 1);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    return 0;
}