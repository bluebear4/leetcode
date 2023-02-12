#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class Allocator {
    struct node {
        int sz;
        bool used;
        int mID;
    };
    list<node> memory;

    void Merge() {
        for (auto it = memory.begin(); it != memory.end(); ++it) {
            if (it->used) continue;
            auto nxt = next(it, 1);
            while (nxt != memory.end() && nxt->used == false) {
                it->sz += nxt->sz;
                memory.erase(nxt);
                nxt = next(it, 1);
            }
        }
    }

   public:
    Allocator(int n) { memory.push_back({n, false, -1}); }

    int allocate(int size, int mID) {
        int index = 0;
        for (auto it = memory.begin(); it != memory.end(); ++it) {
            if (it->sz < size || it->used) {
                index += it->sz;
                continue;
            }
            memory.insert(it, {size, true, mID});
            it->sz -= size;
            return index;
        }
        return -1;
    }

    int free(int mID) {
        int sum = 0;
        for (auto &it : memory) {
            if (it.mID == mID && it.used == true) {
                it.used = false;
                sum += it.sz;
            }
        }
        Merge();
        return sum;
    }
};
int main() { return 0; }