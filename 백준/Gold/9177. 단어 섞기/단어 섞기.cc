#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;

    for (int j = 1; j <= T; j++) {
        queue<pair<int, int>> q;
        string s1, s2, res;
        bool pass = true;
        int idx1 = 0, idx2 = 0;

        cin >> s1 >> s2 >> res;
        vector<vector<bool>> checked(s1.size(), vector<bool>(s2.size()));

        for (int i = 0; i < res.size(); i++) {
            if (idx1 < s1.size() && s1[idx1] == res[i] && s2[idx2] == res[i]) {
                if (!checked[idx1][idx2]) q.push({ idx1, idx2 });
                checked[idx1][idx2] = true;
                idx1++;
            }

            else if (idx1 < s1.size() && s1[idx1] == res[i]) idx1++;

            else if (idx2 < s2.size() && s2[idx2] == res[i]) idx2++;

            else {
                if (!q.empty()) {
                    idx1 = q.front().first;
                    idx2 = q.front().second;
                    i = idx1 + idx2;
                    idx2++;
                    q.pop();
                }

                else {
                    pass = false;
                    break;
                }
            }
        }

        if (pass) cout << "Data set " << j << ": yes" << "\n";
        else cout << "Data set " << j << ": no" << "\n";
    }

    return 0;
}