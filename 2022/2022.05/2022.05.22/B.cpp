#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks,
                    int additionalRocks) {
        priority_queue<int> pq;
        for (int i = 0; i < rocks.size(); ++i) {
            pq.push(rocks[i] - capacity[i]);
        }
        int ans = 0;
        while (pq.size() && additionalRocks >= -pq.top()) {
            additionalRocks += pq.top();
            ++ans;
            pq.pop();
        }
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}