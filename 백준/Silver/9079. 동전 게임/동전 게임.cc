#include <bits/stdc++.h>

using namespace std;

char a[3][3];
int ans = 1001;
bool visited_x[3], visited_y[3], visited_d[2];

bool check() {
    char ch = a[0][0];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (ch != a[i][j]) return false;
        }
    }

    return true;
}

void go(int cnt) {
    if (check()) {
        ans = min(ans, cnt);
        return;
    }

    for (int i = 0; i < 3; i++) {
        if (visited_x[i]) continue;

        for (int j = 0; j < 3; j++)
            a[i][j] = (a[i][j] == 'H' ? 'T' : 'H');

        visited_x[i] = true;
        go(cnt + 1);
        visited_x[i] = false;

        for (int j = 0; j < 3; j++)
            a[i][j] = (a[i][j] == 'H' ? 'T' : 'H');
    }

    for (int j = 0; j < 3; j++) {
        if (visited_y[j]) continue;

        for (int i = 0; i < 3; i++)
            a[i][j] = (a[i][j] == 'H' ? 'T' : 'H');

        visited_y[j] = true;
        go(cnt + 1);
        visited_y[j] = false;

        for (int i = 0; i < 3; i++)
            a[i][j] = (a[i][j] == 'H' ? 'T' : 'H');
    }

    if (!visited_d[0]) {
        for (int i = 0; i < 3; i++)
            a[i][i] = (a[i][i] == 'H' ? 'T' : 'H');

        visited_d[0] = true;
        go(cnt + 1);
        visited_d[0] = false;

        for (int i = 0; i < 3; i++)
            a[i][i] = (a[i][i] == 'H' ? 'T' : 'H');
    }

    if (!visited_d[1]) {
        for (int i = 0; i < 3; i++)
            a[i][2 - i] = (a[i][2 - i] == 'H' ? 'T' : 'H');

        visited_d[1] = true;
        go(cnt + 1);
        visited_d[1] = false;

        for (int i = 0; i < 3; i++)
            a[i][2 - i] = (a[i][2 - i] == 'H' ? 'T' : 'H');
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> a[i][j];
            }
        }

        go(0);
        if (ans == 1001) cout << "-1\n";
        else cout << ans << "\n";
        ans = 1001;
    }
    return 0;
}