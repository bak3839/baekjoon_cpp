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
        queue<vector<int>> q;
        string s1, s2, res;
        bool pass = true;
        int index1 = 0, index2 = 0;

        cin >> s1 >> s2 >> res;
        vector<vector<bool>> visited(s1.size(), vector<bool>(s2.size()));

        for (int i = 0; i < res.size(); i++) {
            if (index1 < s1.size() && s1[index1] == res[i] && s2[index2] == res[i]) {
                if (!visited[index1][index2]) q.push({ i, index1, index2 });
                visited[index1][index2] = true;
                index1++;
            }

            else if (index1 < s1.size() && s1[index1] == res[i]) index1++;

            else if (index2 < s2.size() && s2[index2] == res[i]) index2++;

            else {
                if (!q.empty()) {
                    i = q.front()[0];
                    index1 = q.front()[1];
                    index2 = q.front()[2] + 1;
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