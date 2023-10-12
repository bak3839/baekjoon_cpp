#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;
using pii = pair<int, int>;

int N, M;
bool flag = true;
vector<vector<int>> map;
vector<vector<bool>> visit;

int mv[8][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };

void bfs(int x, int y) {
    queue<pii> q;
    q.push({ x, y });
    visit[x][y] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = x + mv[i][0];
            int ny = y + mv[i][1];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (map[x][y] < map[nx][ny]) flag = false;
            if (visit[nx][ny] || map[nx][ny] != map[x][y]) continue;

            q.push({ nx, ny });
            visit[nx][ny] = true;            
        }
    }
}

void Solution() {
    int ans = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visit[i][j]) continue;

            flag = true;
            bfs(i, j);
            if(flag) ans++;
        }
    }

    cout << ans;
}

void Input() {
    cin >> N >> M;

    map.resize(N, vector<int>(M));
    visit.resize(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> map[i][j];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}
