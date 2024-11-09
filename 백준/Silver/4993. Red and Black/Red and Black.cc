#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int N, M;
int mv[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
vector<string> map;

void BFS(int a, int b) {
    int ans = 1;

    queue<pii> q;
    q.push({ a, b });
    map[a][b] = '#';

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + mv[i][0];
            int ny = y + mv[i][1];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M || map[nx][ny] == '#') continue;

            ans++;
            map[nx][ny] = '#';
            q.push({ nx, ny });
        }
    }

    cout << ans << "\n";
}

void Solution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if(map[i][j] != '@') continue;

            BFS(i, j);
            goto escape;
        }
    }

    escape:
    map.clear();
}

void Input() {
    while(1) {
        cin >> M >> N;

        if(N == 0 && M == 0) break;

        map.resize(N);

        for (int i = 0; i < N; i++)
            cin >> map[i];
        Solution();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    return 0;
}