#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, x, y, ans;
int mv[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
vector<vector<char>> map;

void bfs() {
    queue<pair<int, int>> q;
    q.push({ x, y });
    map[x][y] = '*';

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0;i < 4;i++) {
            int nx = x + mv[i][0];
            int ny = y + mv[i][1];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (map[nx][ny] == 'X' || map[nx][ny] == '*') continue;
            if (map[nx][ny] == 'P') ans++;

            map[nx][ny] = '*';
            q.push({ nx, ny });
        }
    }
}

void Solution() {
    bfs();

    if (ans > 0) cout << ans;
    else cout << "TT";
}

void Input() {
    cin >> N >> M;

    map.resize(N, vector<char>(M));

    for (int i = 0;i < N;i++) {
        for (int j = 0;j < M;j++) {
            cin >> map[i][j];
            if (map[i][j] == 'I') {
                x = i; y = j;
            }
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