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

        cin >> s1 >> s2 >> res;
        vector<vector<bool>> checked(s1.size() + 1, vector<bool>(s2.size() + 1, false));

        q.push({ 0, 0 });

        while (!q.empty()) {
            int idx1 = q.front().first;
            int idx2 = q.front().second;
            q.pop();

            if (idx1 < s1.size() && s1[idx1] == res[idx1 + idx2] && !checked[idx1 + 1][idx2]) {
                q.push({ idx1 + 1, idx2 });
                checked[idx1 + 1][idx2] = true;
            }

            if (idx2 < s2.size() && s2[idx2] == res[idx1 + idx2] && !checked[idx1][idx2 + 1]) {
                q.push({ idx1, idx2 + 1 });
                checked[idx1][idx2 + 1] = true;
            }
        }

        if (checked[s1.size()][s2.size()]) cout << "Data set " << j << ": yes" << "\n";
        else cout << "Data set " << j << ": no" << "\n";
    }

    return 0;
}