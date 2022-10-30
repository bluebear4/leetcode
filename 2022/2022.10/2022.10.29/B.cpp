#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    vector<string> twoEditWords(vector<string>& queries,
                                vector<string>& dictionary) {
        vector<string> ans;
        for (auto& querie : queries) {
            for (auto& it : dictionary) {
                int cnt = 0;
                for (int i = 0; i < querie.length(); ++i) {
                    if (querie[i] != it[i]) ++cnt;
                }
                if (cnt <= 2) {
                    ans.emplace_back(querie);
                    break;
                }
            }
        }
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}