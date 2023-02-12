#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
    ListNode* dfs(ListNode* now) {
        if (now == nullptr) return now;
        if (now->next == nullptr) return now;
        ListNode* temp = dfs(now->next);
        if (temp->val > now->val) return temp;
        now->next = temp;
        return now;
    }

   public:
    ListNode* removeNodes(ListNode* head) {
        return dfs(head);
    }
};
int main() {
    return 0;
}