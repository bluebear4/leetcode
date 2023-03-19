#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> cnt(value);
        for (auto& num : nums) cnt[((num % value) + value) % value]++;
        int mini = *min_element(cnt.begin(), cnt.end());
        int ans = mini * value;
        for (int i = 0; i < value; ++i) {
            if (cnt[i] <= mini) break;
            ++ans;
        }
        return ans;
    }
};
int main() {
    return 0;
}