#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        //根不为孩子
        //不能a,b b,a同时 必有一个满足
        //不存在节点同时为多个节点的孩子 0到1个满足
        //son[x] 孩子为x的边
    }
};
int main() {
    vector<vector<int>> a{{0, 1, 3, 2}, {5, 1, 2, 5}, {4, 3, 8, 6}};
    Solution().minimumTime(a);
    return 0;
}