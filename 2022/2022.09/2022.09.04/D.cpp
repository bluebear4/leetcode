#include <bits/stdc++.h>
using namespace std;
#define rall(x) x.rbegin(), x.rend()
class Solution {
#define all(x) x.begin(), x.end()
    using ll = long long;

   public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(all(meetings));
        set<int> empty;
        map<ll, set<int>> busy;
        unordered_map<int, int> ans;

        for (int i = 0; i < n; ++i) empty.insert(i);
        for (auto& meeting : meetings) {
            //释放会议室
            while (busy.size() && busy.begin()->first <= meeting[0]) {
                for (auto& it : busy.begin()->second) empty.insert(it);
                busy.erase(busy.begin());
            }

            if (empty.size()) {  //有未占用的
                int id = *empty.begin();
                busy[meeting[1]].insert(id);
                ans[id]++;
                empty.erase(empty.begin());
            } else {  //延期
                while (busy.size() && busy.begin()->second.empty()) {
                    busy.erase(busy.begin());
                }
                int id = *busy.begin()->second.begin();
                busy.begin()->second.erase(busy.begin()->second.begin());
                busy[busy.begin()->first + meeting[1] - meeting[0]].insert(id);
                ans[id]++;
            }
        }
        int id = 0, cnt = ans[0];
        for (auto& [k, v] : ans) {
            if (v > cnt) {
                id = k, cnt = v;
            } else if (v == cnt) {
                id = min(id, k);
            }
        }
        return id;
    }
};
int main() {
    vector<vector<int>> a{{1, 20}, {2, 10}, {3, 5}, {4, 9}, {6, 8}};

    Solution().mostBooked(3, a);
    return 0;
}