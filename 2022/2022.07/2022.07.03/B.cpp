#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
   public:
    vector<vector<int>> spiralMatrix(int n, int m, ListNode *head) {
        vector<vector<int>> ans(n, vector<int>(m, -1));
        int ways[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}, index = 0;
        int x = 0, y = 0;
        while (head) {
            ans[x][y] = head->val;
            head = head->next;
            if (head == nullptr) break;
            while (1) {
                int i = x + ways[index][0];
                int j = y + ways[index][1];
                if (i >= 0 && i < n && j >= 0 && j < m && ans[i][j] == -1) {
                    x = i;
                    y = j;
                    break;
                } else {
                    index = (index + 1) % 4;
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