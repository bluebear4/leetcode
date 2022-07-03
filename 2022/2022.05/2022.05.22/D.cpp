#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
    using ll = long long;
    const int mod = 1e9 + 7;

   public:
    int totalStrength(vector<int>& nums) {
        nums.insert(nums.begin(), 0);
        nums.push_back(0);
        int n = nums.size();
        vector<ll> sum(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i) sum[i] += sum[i - 1];
            sum[i] %= mod;
        }
        vector<ll> sum2(sum.begin(), sum.end());
        for (int i = 0; i < n; i++) {
            if (i) sum2[i] += sum2[i - 1];
            sum2[i] %= mod;
        }
        stack<int> st;
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            // 1 3 1 2
            // 1 4 5 7
            // 1 5 10 17
            // sum2[r-(l-1)] - len*sum[l-1]
            while (!st.empty() && nums[i] < nums[st.top()]) {
                int nowID = st.top();
                st.pop();

                int leftID = -1;
                if (!st.empty()) leftID = st.top();

                int rightID = i;

                // ans += (sum2[rightID - 1] - sum2[leftID] -
                //         sum[leftID] * (rightID - 1 - leftID)) *
                //        nums[nowID] % mod;
                ans += (sum2[rightID - 1] - sum2[nowID] -
                        sum[nowID] * (rightID - 1 - nowID)) *
                       nums[nowID] % mod;
                ans += (sum2[nowID] - sum2[leftID] -
                        sum[leftID] * (nowID - leftID)) *
                       nums[nowID] % mod;

                ans +=
                    (sum[rightID - 1] - sum[nowID - 1] * (nowID - 1 - leftID)) *
                    nums[nowID] % mod;

                ans += (sum[nowID - 1] - sum[leftID] * (rightID - 1 - nowID)) *
                       nums[nowID] % mod;
                ans %= mod;
            }
            st.push(i);
        }
        return ans;
    }
};
int main() {
    vector<int> a{1, 3, 1, 2};
    Solution().totalStrength(a);
    return 0;
}