#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rall(x) x.rbegin(), x.rend()
class Solution {
    int f(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

   public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, multiset<int>> cnt;
        for (auto num : nums) {
            cnt[f(num)].insert(num);
        }
        int ans = -1;
        for (auto& [k, v] : cnt) {
            if (v.size() > 1) {
                ans = max(ans, *v.rbegin() + *++v.rbegin());
            }
        }
        return ans;
    }
};
int main() {
    return 0;
}