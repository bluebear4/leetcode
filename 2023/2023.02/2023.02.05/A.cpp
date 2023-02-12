#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for (auto& it : gifts) pq.emplace(it);
        while (k--) {
            int now = sqrt(pq.top() + 0.5);
            pq.pop();
            pq.emplace(now);
        }
        long long ans = 0;
        while (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};
int main() { return 0; }