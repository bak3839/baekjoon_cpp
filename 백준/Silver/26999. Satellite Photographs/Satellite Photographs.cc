#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int W, H;
vector<string> A;
int mv[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

int Bfs(int a, int b) {
    int cnt = 1;

    queue<pii> q;
    q.push({ a, b });
    A[a][b] = '.';

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + mv[i][0];
            int ny = y + mv[i][1];

            if (nx < 0 || ny < 0 || nx >= H || ny >= W || A[nx][ny] == '.') continue;

            q.push({ nx, ny });
            A[nx][ny] = '.';
            cnt++;
        }
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ans = 0;
    cin >> W >> H;

    A.resize(H);

    for (int i = 0; i < H; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (A[i][j] == '.') continue;

            ans = max(ans, Bfs(i, j));
        }
    }

    cout << ans;
    return 0;
}
