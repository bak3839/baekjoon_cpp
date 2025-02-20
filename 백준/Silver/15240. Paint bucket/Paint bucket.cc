#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int R, C;
vector<string> A;
int mv[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

void Bfs(int a, int b, char k) {
    char c = A[a][b];

    if (c == k) return;

    queue<pii> q;
    q.push({ a, b });
    A[a][b] = k;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + mv[i][0];
            int ny = y + mv[i][1];

            if (nx < 0 || ny < 0 || nx >= R || ny >= C || A[nx][ny] != c) continue;

            q.push({ nx, ny });
            A[nx][ny] = k;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ans = 0, x, y;
    char k;
    cin >> R >> C;

    A.resize(R);

    for (int i = 0; i < R; i++)
        cin >> A[i];
    cin >> x >> y >> k;

    Bfs(x, y, k);

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++)
            cout << A[i][j];
        cout << "\n";
    }
    return 0;
}
