#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int mv[8][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1,-1}, {1, 1}, {-1, 1}, {1, -1} };
vector<vector<int>> map;

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({ x, y });
    map[x][y] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0;i < 8;i++) {
            int nx = x + mv[i][0];
            int ny = y + mv[i][1];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (map[nx][ny] == 0) continue;

            map[nx][ny] = 0;
            q.push({ nx, ny });
        }
    }
}

void Solution() {
    int ans = 0;

    for (int i = 0;i < N;i++) {
        for (int j = 0;j < M;j++) {
            if (map[i][j] == 1) {
                bfs(i, j);
                ans++;
            }
        }
    }

    cout << ans;
}

void Input() {
    cin >> N >> M;

    map.resize(N, vector<int>(M));

    for (int i = 0;i < N;i++) {
        for (int j = 0;j < M;j++)
            cin >> map[i][j];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}