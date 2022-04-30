#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
//字典树。。
class Encrypter {
    vector<char> keys;
    vector<string> values;
    unordered_map<int, int> keysHash;
    unordered_map<string, vector<int>> valuesHash;
    class Trie {
        static const int sz = 26;
        struct node {
            int end;
            int child[sz];
        };
        int pos = 0;
        int creat() {
            pos++;
            for (int i = 0; i < sz; i++) tree[pos].child[i] = -1;
            return pos;
        }

       public:
        vector<node> tree;
        Trie(int _n) : tree(_n + 1) {
            for (int i = 0; i < sz; ++i) {
                tree[0].child[i] = -1;
            }
        }
        void insert(const string &str) {
            int post = 0;
            for (int i = 0; i < str.size(); i++) {
                int m = str[i] - 'a';
                if (tree[post].child[m] == -1) tree[post].child[m] = creat();
                post = tree[post].child[m];
            }
            tree[post].end = 1;
            return;
        }
    } T;

   public:
    Encrypter(vector<char> &k, vector<string> &v, vector<string> &d)
        : values(v), keys(k), T(10005) {
        for (auto &it : d) T.insert(it);
        for (int i = 0; i < k.size(); ++i) keysHash[k[i]] = i;
        for (int i = 0; i < v.size(); ++i) valuesHash[v[i]].emplace_back(i);
    }

    string encrypt(string word1) {
        string ret;
        for (auto &it : word1) {
            ret += values[keysHash[it]];
        }
        return ret;
    }
    struct node {
        int root, index;
        node(int r, int i) : root(r), index(i) {}
    };

    int decrypt(string word2) {
        queue<node> q;
        q.emplace(0, 0);
        int ans = 0;
        while (q.size()) {
            node t = q.front();
            q.pop();
            string str = word2.substr(t.index, 2);
            for (auto &it : valuesHash[str]) {
                int nxt = T.tree[t.root].child[keys[it] - 'a'];
                if (nxt != -1) {
                    if (t.index + 2 == word2.length()) {
                        ans += T.tree[nxt].end;
                    } else {
                        q.emplace(nxt, t.index + 2);
                    }
                }
            }
        }
        return ans;
    }
};
class Encrypter {
    vector<string> values;
    unordered_map<int, int> keysHash;
    unordered_map<string, int> ans;

   public:
    Encrypter(vector<char> &k, vector<string> &v, vector<string> &d)
        : values(v) {
        for (int i = 0; i < k.size(); ++i) keysHash[k[i]] = i;
        for (auto &it : d) ++ans[encrypt(it)];
    }

    string encrypt(string word1) {
        string ret;
        for (auto &it : word1) {
            ret += values[keysHash[it]];
        }
        return ret;
    }

    int decrypt(string word2) { return ans[word2]; }
};
int main() {
    // Solution()
    return 0;
}