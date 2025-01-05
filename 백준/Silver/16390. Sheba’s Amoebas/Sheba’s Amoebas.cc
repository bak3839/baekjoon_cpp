#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int N, M;
int mv[8][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1} };
vector<string> v;

void bfs(int a, int b) {
    queue<pii> q;
    q.push({ a, b });
    v[a][b] = '.';

    int x, y, nx, ny;

    while (q.size()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            nx = x + mv[i][0];
            ny = y + mv[i][1];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M || v[nx][ny] == '.') continue;

            v[nx][ny] = '.';
            q.push({ nx, ny });
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ans = 0;
    cin >> N >> M;

    v.resize(N);

    for (int i = 0; i < N; i++)
        cin >> v[i];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (v[i][j] == '.') continue;

            bfs(i, j);
            ans++;
        }
    }

    cout << ans;
    return 0;
}