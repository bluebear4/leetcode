#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int minNumberOfHours(int initialEnergy, int initialExperience,
                         vector<int>& energy, vector<int>& experience) {
        int ans = 0;
        for (int i = 0; i < energy.size(); ++i) {
            if (initialEnergy <= energy[i]) {
                ans += energy[i] + 1 - initialEnergy;
                initialEnergy = energy[i] + 1;
            }
            if (initialExperience <= experience[i]) {
                ans += experience[i] + 1 - initialExperience;
                initialExperience = experience[i] + 1;
            }
            initialEnergy -= energy[i];
            initialExperience += experience[i];
        }
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}