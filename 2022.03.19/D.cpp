#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

//假做法-> cout<<Solution().minimumWhiteTiles("0101111010"s, 2, 4);

class Solution {
    int n, ans;
    vector<vector<int>> f;

    void update(int i, int j, int v) {
        if (i >= n)
            ans = min(ans, v);
        else
            f[i][j] = min(f[i][j], v);
    }

   public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        n = floor.size();
        for (int i = 0; i < n; i++) {
            f.push_back(vector<int>());
            for (int j = 0; j <= numCarpets; j++) f[i].push_back(1e9);
        }
        f[0][0] = 0;
        ans = 1e9;
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= numCarpets; j++) {
                update(i + 1, j, f[i][j] + floor[i] - '0');
                if (j < numCarpets) update(i + carpetLen, j + 1, f[i][j]);
            }
        return ans;
    }
};

// 作者：TsReaper
// 链接：https://leetcode-cn.com/circle/discuss/bdMSIh/view/vxDgMk/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

int main() {
    cout << Solution().minimumWhiteTiles("0101111010", 2, 4);
    return 0;
}