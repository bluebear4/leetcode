#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class BookMyShow {
    using ll = long long;
    map<int, int> remain;
    map<int, set<int>> rows;
    int M;
    int block;
    vector<ll> blocks;

   public:
    BookMyShow(int n, int m)
        : M(m), block(ceil(sqrt(n))), blocks(ceil(sqrt(n)) + 1) {
        for (int i = 0; i < n; ++i) {
            rows[m].insert(i);
            remain[i] = m;
            blocks[i / block] += m;
        }
    }

    vector<int> gather(int k, int maxRow) {
        auto it = rows.lower_bound(k);

        if (it == rows.end()) return vector<int>{};

        if (it->second.empty()) {
            rows.erase(it);
            return gather(k, maxRow);
        }

        int row = *(it->second.begin());

        if (row > maxRow) return vector<int>{};

        vector<int> ans{row, M - it->first};

        if (it->first - k) rows[it->first - k].insert(row);
        it->second.erase(it->second.begin());

        remain[row] -= k;
        if (remain[row] == 0) {
            remain.erase(row);
        }

        blocks[row / block] -= k;

        return ans;
    }
    // 9->3*3
    // 6
    bool scatter(int k, int maxRow) {
        ll sum = 0;
        for (int i = 0; i < maxRow / block && sum < k; ++i) {
            sum += blocks[i];
        }
        for (auto it = remain.lower_bound(maxRow / block * block);
             it != remain.end() && it->first <= maxRow && sum < k; ++it) {
            sum += it->second;
        }
        if (sum < k) return false;

        for (auto it = remain.begin(); k;) {
            int row = it->first, cnt = it->second;
            if (k >= cnt) {
                rows[cnt].erase(row);
                blocks[row / block] -= cnt;
                it = remain.erase(it);
            } else {
                rows[cnt - k].insert(row);
                rows[cnt].erase(row);
                blocks[row / block] -= k;
                it->second -= k;
            }
            k -= min(k, cnt);
        }

        return true;
    }
};

int main() {
    BookMyShow t{25, 941};

    t.gather(34, 1);
    t.gather(296, 21);
    t.gather(927, 18);
    t.gather(695, 15);
    t.gather(830, 22);
    t.gather(638, 2);
    t.gather(169, 15);
    // t.gather(623, 16);

    // t.scatter(6, 16);
    return 0;
}