#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
class FoodRatings {
    struct node {
        int rating;
        string name;
        bool operator<(const node& r) const {
            if (rating != r.rating) return rating > r.rating;
            return name < r.name;
        }
        node(int x, string y) : rating(x), name(y) {}
        node() = default;
    };

    unordered_map<string, set<node>> ans;
    unordered_map<string, node> index;

   public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines,
                vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; ++i) {
            ans[cuisines[i]].emplace(ratings[i], foods[i]);
            index[foods[i]] = node{ratings[i], cuisines[i]};
        }
    }

    void changeRating(string food, int newRating) {
        node& x = index[food];
        int rating = x.rating;
        string cuisine = x.name;
        x.rating = newRating;

        ans[cuisine].erase(node{rating, food});
        ans[cuisine].insert(node{newRating, food});
    }

    string highestRated(string cuisine) { return ans[cuisine].begin()->name; }
};
int main() {
    // Solution()
    return 0;
}