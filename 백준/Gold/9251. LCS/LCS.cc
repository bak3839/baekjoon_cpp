#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s1, s2;
    int res = 0;
    cin >> s1 >> s2;

    vector<vector<int>> lcs(s1.size() + 1, vector<int>(s2.size() + 1, 0));

    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            if (s1[i - 1] == s2[j - 1]) {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
                res = max(res, lcs[i][j]);
            }

            else lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
        }
    }

    cout << res;
    return 0;
}