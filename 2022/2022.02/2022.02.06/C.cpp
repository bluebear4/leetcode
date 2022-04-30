#include <bits/stdc++.h>
using namespace std;
// #define all(x) x.begin(), x.end()
// #define rall(x) x.rbegin(), x.rend()
class Bitset {
    using ull = unsigned long long;
    vector<bool> b;
    int cnt;

   public:
    Bitset(int size) {
        cnt = 0;
        b.resize(size);
    }

    void fix(int idx) {
        if (b[idx] == 0) ++cnt;
        b[idx] = 1;
    }

    void unfix(int idx) {
        if (b[idx] == 1) --cnt;
        b[idx] = 0;
    }

    void flip() {
        b.flip();
        cnt = b.size() - cnt;
    }

    bool all() {
        return b.size() == cnt;
        ;
    }

    bool one() { return cnt > 0; }

    int count() { return cnt; }

    string toString() {
        string ans;
        for (int i = 0; i < b.size(); ++i) {
            ans += '0' + b[i];
        }
        return ans;
    }
};
int main() {
    // Solution()
    return 0;
}