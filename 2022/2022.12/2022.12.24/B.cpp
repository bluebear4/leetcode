#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    vector<int> topStudents(vector<string>& pf, vector<string>& nf,
                            vector<string>& report, vector<int>& student_id,
                            int k) {
        unordered_set<string> p(pf.begin(), pf.end());
        unordered_set<string> n(nf.begin(), nf.end());

        vector<int> score(student_id.size());
        for (int i = 0; i < report.size(); ++i) {
            string& s = report[i];
            int pos = 0;
            while (pos != string::npos) {
                auto nxt = s.find(' ', pos);
                if (nxt == string::npos) {
                    if (p.count(s.substr(pos))) score[i] += 3;
                    if (n.count(s.substr(pos))) score[i] -= 1;
                    break;
                }
                if (p.count(s.substr(pos, nxt - pos))) score[i] += 3;
                if (n.count(s.substr(pos, nxt - pos))) score[i] -= 1;
                pos = nxt + 1;
            }
        }

        unordered_map<int, int> id2id;
        for (int i = 0; i < student_id.size(); ++i) {
            id2id[student_id[i]] = i;
        }

        sort(student_id.begin(), student_id.end(),
             [&score, &id2id](int x, int y) {
                 if (score[id2id[x]] != score[id2id[y]])
                     return score[id2id[x]] > score[id2id[y]];
                 return x < y;
             });
        return {student_id.begin(), student_id.begin() + k};
    }
};
int main() {
    vector<string> a{"smart", "brilliant", "studious"};
    vector<string> b{"not"};
    vector<string> c{"this student is not studious", "the student is smart"};
    vector<int> d{1, 2};
    Solution().topStudents(a, b, c, d, 2);
    return 0;
}