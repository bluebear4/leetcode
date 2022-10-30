#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class LUPrefix {
    int n;
    vector<int> right;

   public:
    LUPrefix(int _n) : n(_n), right(_n + 2) {
        iota(right.begin(), right.end(), 0);
    }

    void merge(int x) { right[x] = right[x + 1]; }

    int get(int x) {
        if (right[x] != x) return right[x] = get(right[x]);
        return right[x];
    }
    void upload(int video) { merge(video); }

    int longest() { return get(1); }
};

int main() {
    // Solution()
    return 0;
}