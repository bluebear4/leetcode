#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rall(x) x.rbegin(), x.rend()
class Solution {
#define all(x) x.begin(), x.end()
   public:
    int temperatureTrend(vector<int>& temperatureA, vector<int>& temperatureB) {
        for (int i = 0; i + 1 < temperatureA.size(); ++i) {
            if (temperatureA[i + 1] > temperatureA[i]) {
                temperatureA[i] = 1;
            } else if (temperatureA[i + 1] < temperatureA[i]) {
                temperatureA[i] = -1;
            } else {
                temperatureA[i] = 0;
            }
            if (temperatureB[i + 1] > temperatureB[i]) {
                temperatureB[i] = 1;
            } else if (temperatureB[i + 1] < temperatureB[i]) {
                temperatureB[i] = -1;
            } else {
                temperatureB[i] = 0;
            }
        }
        temperatureA.pop_back();
        temperatureB.pop_back();
        vector<int> ans(temperatureA.size());
        for (int i = 0; i < temperatureA.size(); ++i) {
            ans[i] = (temperatureA[i] == temperatureB[i]);
            if (ans[i] && i) ans[i] += ans[i - 1];
        }
        return *max_element(all(ans));
    }
};
int main() {
    // Solution()
    return 0;
}