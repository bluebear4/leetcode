#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class CountIntervals {
    int cnt = 0;
    using pii = pair<int, int>;
    set<pii> qj;

   public:
    CountIntervals() {}

    void add(int left, int right) {
        if (qj.count(make_pair(left, right))) return;

        cnt += right - left + 1;
        auto now = qj.insert(make_pair(left, right)).first;

        while (next(now, 1) != qj.end()) {
            auto r = next(now, 1);
            if (r->first <= now->second) {
                // now.l r.l now.r r.r
                // now.l r.l r.r now.r
                if (r->second <= now->second) {
                    {
                        cnt -= r->second - r->first + 1;
                        qj.erase(r);
                    }
                } else {
                    left = min(now->first, r->first);
                    right = max(now->second, r->second);

                    cnt -= r->second - r->first + 1;
                    qj.erase(r);

                    cnt -= now->second - now->first + 1;
                    qj.erase(now);

                    cnt += right - left + 1;
                    now = qj.insert(make_pair(left, right)).first;
                }
            } else {
                break;
            }
        }

        while (now != qj.begin() && now != qj.end()) {
            auto l = next(now, -1);
            if (l->second >= now->first) {
                // l.l now.l l.r now.r
                // l.l now.l now.r l.r
                if (now->second <= l->second) {
                    cnt -= now->second - now->first + 1;
                    qj.erase(now);
                    break;
                } else {
                    left = min(now->first, l->first);
                    right = max(now->second, l->second);

                    cnt -= now->second - now->first + 1;
                    qj.erase(now);

                    cnt -= l->second - l->first + 1;
                    qj.erase(l);

                    cnt += right - left + 1;
                    now = qj.insert(make_pair(left, right)).first;
                }
            } else {
                break;
            }
        }
        return;
    }

    int count() { return cnt; }
};
int main() {
    auto t = CountIntervals{};
    t.add(5, 10);
    t.add(5, 10);
    cout << t.count() << endl;
    return 0;
}