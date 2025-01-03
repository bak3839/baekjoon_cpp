#include <bits/stdc++.h>

using namespace std;

int N, M, T;
int mv[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
vector<vector<int>> v;
bool visited[2][101][101];

struct A {
    int x, y, gram;
};

int bfs() {
    queue<A> q;
    q.push({ 0, 0, 0 });
    visited[0][0][0] = true;

    bool gram, nGram;
    int size, x, y, nx, ny, cnt = 0;

    while (q.size()) {
        size = q.size();

        while (size--) {
            x = q.front().x;
            y = q.front().y;
            gram = q.front().gram;
            q.pop();

            if (x == N - 1 && y == M - 1) return cnt;

            for (int i = 0; i < 4; i++) {
                nx = x + mv[i][0];
                ny = y + mv[i][1];
                 
                if (nx < 0 || ny < 0 || nx >= N || ny >= M || visited[gram][nx][ny]) continue;
                if (!gram && (v[nx][ny] == 1)) continue;

                if (v[nx][ny] == 2) nGram = 1;
                else nGram = gram;

                visited[nGram][nx][ny] = true;
                q.push({ nx, ny, nGram });
            }
        }
        cnt++;
        if (cnt > T) break;
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ans;
    cin >> N >> M >> T;
    v.resize(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cin >> v[i][j];
    }

    ans = bfs();

    if (ans == -1) cout << "Fail";
    else cout << ans;

    return 0;
}