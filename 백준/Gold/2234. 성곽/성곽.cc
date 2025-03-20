#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

struct A {
    int dx; int dy; int dir;
};

A wall[4] = { {0, -1, 1}, {-1, 0, 2}, {0, 1, 4}, {1, 0, 8} };
int N, M, room, max_room, rm_max_room;
int R[51][51], visited[51][51], room_size[2501];

void bfs(int a, int b, int cnt) {
    int res = 1;
    queue<pii> q;
    q.push({ a, b });
    visited[a][b] = cnt;

    while (q.size()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            if (R[x][y] & wall[i].dir) continue;

            int nx = x + wall[i].dx;
            int ny = y + wall[i].dy;

            if (nx < 0 || ny < 0 || nx >= N || ny >= M || visited[nx][ny]) continue;

            res++;
            q.push({ nx, ny });
            visited[nx][ny] = cnt;
        }
    }

    room_size[cnt] = res;
    max_room = max(max_room, res);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cin >> R[i][j];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j]) continue;

            room++;
            bfs(i, j, room);
        }
    }

    int a, b;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i < N - 1) {
                a = visited[i][j];
                b = visited[i + 1][j];

                if (a != b) {
                    rm_max_room = max(rm_max_room, room_size[a] + room_size[b]);
                }
            }

            if (j < M - 1) {
                a = visited[i][j];
                b = visited[i][j + 1];

                if (a != b) {
                    rm_max_room = max(rm_max_room, room_size[a] + room_size[b]);
                }
            }
        }
    }

    cout << room << "\n" << max_room << "\n" << rm_max_room;
    return 0;
}