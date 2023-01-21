#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string str;
    cin >> str;

    int N, n;
    cin >> N;

    vector<vector<int>> cnt(26, vector<int>(str.size(), 0));
    n = str[0] - 97;
    cnt[n][0] = 1;

    for (int i = 1; i < str.size(); i++) {
        n = str[i] - 97;
        for (int j = 0; j < 26; j++) {
            if (j == n) cnt[j][i] = cnt[j][i - 1] + 1;
            else cnt[j][i] = cnt[j][i - 1];
        }
    }

    char ch;
    int a, b;
    for (int i = 0; i < N; i++) {
        cin >> ch >> a >> b;

        if (a == 0) cout << cnt[ch - 97][b] << "\n";
        else cout << cnt[ch - 97][b] - cnt[ch - 97][a - 1] << "\n";
    }

    return 0;
}