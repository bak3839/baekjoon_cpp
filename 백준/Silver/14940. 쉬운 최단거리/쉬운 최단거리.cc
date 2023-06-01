#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

int N, M;
int mv[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
vector<vector<int>> map;
pii p;

void bfs() {
    queue<pii> q;
    q.push({ p.first, p.second });
    map[p.first][p.second] = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        int now = map[x][y];
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + mv[i][0];
            int ny = y + mv[i][1];

            if (nx >= N || nx < 0 || ny >= M || ny < 0) continue;
            if (map[nx][ny] == 0 || map[nx][ny] > 1) continue;
            if (nx == p.first && ny == p.second) continue;

            q.push({ nx, ny });
            map[nx][ny] = now + 1;
        }
    }
}

void Solution() {
    bfs();
    map[p.first][p.second] = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 1) cout << -1 << " ";
            else if (map[i][j] == 0) cout << 0 << " ";
            else cout << map[i][j] - 1 << " ";
        }
        cout << "\n";
    }
}

void Input() {
    cin >> N >> M;
    map.resize(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) p = { i, j };
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}