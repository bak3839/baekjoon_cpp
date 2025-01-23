#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int N;
string input;
vector<vector<int>> ans;

void move(char ch) {

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> input;
    ans.resize(N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            ans[i].push_back(0);
    }

    int x = 0, y = 0, nx = 0, ny = 0;

    for (char ch : input) {
        int res = 0;

        if (ch == 'U') {
            nx = x - 1;
            res = 1;
        }
        else if (ch == 'D') {
            nx = x + 1;
            res = 1;
        }
        else if (ch == 'R') {
            ny = y + 1;
            res = 10;
        }
        else {
            ny = y - 1;
            res = 10;
        }

        if (nx < 0 || ny < 0 || nx >= N || ny >= N) {
            nx = x, ny = y;
            continue;
        }

        if (res == 1 && ans[x][y] % 10 < 1) {
            ans[x][y] += res;
        }
        if (res == 1 && ans[nx][ny] % 10 < 1) {
            ans[nx][ny] += res;
        }

        if (res == 10 && ans[x][y] % 100 < 10) {
            ans[x][y] += res;
        }
        if (res == 10 && ans[nx][ny] % 100 < 10) {
            ans[nx][ny] += res;
        }

        x = nx, y = ny;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int n = ans[i][j];

            if (n == 0) cout << '.';
            else if (n == 1) cout << '|';
            else if (n == 10) cout << '-';
            else cout << '+';
        }
        cout << "\n";
    }

    return 0;
}