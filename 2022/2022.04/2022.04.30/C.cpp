#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Solution {
   public:
    int countUnguarded(int n, int m, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        unordered_map<int, set<int>> rowG, rowW, colG, colW;
        for (auto& guard : guards) {
            rowG[guard[0]].insert(guard[1]);
            colG[guard[1]].insert(guard[0]);
        }
        for (auto& wall : walls) {
            rowW[wall[0]].insert(wall[1]);
            colW[wall[1]].insert(wall[0]);
        }
        int ans = n*m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (rowG[i].count(j) || rowW[i].count(j)) {
                    --ans;
                    continue;
                }
                {
                    auto leftG = rowG[i].lower_bound(j);
                    auto leftW = rowW[i].lower_bound(j);
                    if (leftG != rowG[i].begin()) {
                        --leftG;
                        if (leftW == rowW[i].begin()) {
                            --ans;
                            continue;
                        } else {
                            --leftW;
                            if (*leftG > *leftW) {
                                --ans;
                                continue;
                            }
                        }
                    }else{

                    }
                }
                {
                    auto rightG = rowG[i].upper_bound(j);
                    auto rightW = rowW[i].upper_bound(j);
                    if (rightG != rowG[i].end()) {
                        if (rightW == rowW[i].end()) {
                            --ans;
                            continue;
                        } else {
                            if (*rightG < *rightW) {
                                --ans;
                                continue;
                            }
                        }
                    }
                }
                {
                    auto upG = colG[j].lower_bound(i);
                    auto upW = colW[j].lower_bound(i);
                    if (upG != colG[j].begin()) {
                        --upG;
                        if (upW == colW[j].begin()) {
                            --ans;
                            continue;
                        } else {
                            --upW;
                            if (*upG > *upW) {
                                --ans;
                                continue;
                            }
                        }
                    }
                }
                {
                    auto downG = colG[j].upper_bound(i);
                    auto downW = colW[j].upper_bound(i);
                    if (downG != colG[j].end()) {
                        if (downW == colW[j].end()) {
                            --ans;
                            continue;
                        } else {
                            if (*downG < *downW) {
                                --ans;
                                continue;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
int main() {
    vector<vector<int>> a{{0, 0}, {1, 1}, {2, 3}};
    vector<vector<int>> b{{0, 1}, {2, 2}, {1, 4}};
    Solution().countUnguarded(4, 6, a, b);
    return 0;
}