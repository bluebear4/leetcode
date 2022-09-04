#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class NumberContainers {
    unordered_map<int, int> array;
    unordered_map<int, set<int>> id;

   public:
    NumberContainers() {}

    void change(int index, int number) {
        if (!array.count(index)) {
            array[index] = number;
            id[number].insert(index);
        } else {

            int &value = array[index];
            id[value].erase(index);
            value = number;
            id[number].insert(index);
        }
    }

    int find(int number) {
        if (!id.count(number) || id[number].empty()) return -1;
        return *id[number].begin();
    }
};

int main() {
    // Solution()
    return 0;
}