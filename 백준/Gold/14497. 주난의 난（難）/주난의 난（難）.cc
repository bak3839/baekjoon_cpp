#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int N, M;
vector<string> A;
bool visited[301][301];
int mv[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

bool Jump(int sx, int sy, int ex, int ey) {
    queue<pii> q;
    q.push({ sx, sy });
    visited[sx][sy] = true;

    while (q.size()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == ex && y == ey) return true;

        for (int i = 0; i < 4; i++) {
            int nx = x + mv[i][0];
            int ny = y + mv[i][1];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M || visited[nx][ny]) continue;

            if (A[nx][ny] == '1') A[nx][ny] = '0';
            else q.push({ nx, ny });
            visited[nx][ny] = true;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int sx, sy, ex, ey, ans = 1;
    cin >> N >> M;
    cin >> sx >> sy >> ex >> ey;

    A.resize(N);

    for (int i = 0; i < N; i++)
        cin >> A[i];

    while (!Jump(sx - 1, sy - 1, ex - 1, ey - 1)) {
        ans++;
        memset(visited, false, sizeof(visited));
    }

    cout << ans;
    return 0;
}
