#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class ATM {
    using ll = long long;
    unordered_map<int, ll> cnt;

   public:
    ATM() {}

    void deposit(vector<int> banknotesCount, int save = 1) {
        cnt[20] += banknotesCount[0] * save;
        cnt[50] += banknotesCount[1] * save;
        cnt[100] += banknotesCount[2] * save;
        cnt[200] += banknotesCount[3] * save;
        cnt[500] += banknotesCount[4] * save;
    }

    vector<int> withdraw(int amount) {
        vector<int> ret(5);
        ret[4] = min<ll>(cnt[500], amount / 500);
        amount -= ret[4] * 500;
        ret[3] = min<ll>(cnt[200], amount / 200);
        amount -= ret[3] * 200;
        ret[2] = min<ll>(cnt[100], amount / 100);
        amount -= ret[2] * 100;
        ret[1] = min<ll>(cnt[50], amount / 50);
        amount -= ret[1] * 50;
        ret[0] = min<ll>(cnt[20], amount / 20);
        amount -= ret[0] * 20;
        if (amount == 0) {
            deposit(ret, -1);
            return ret;
        } else {
            return vector<int>{-1};
        }
    }
};

int main() {
    // Solution()
    return 0;
}