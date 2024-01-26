#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int N, M, ans = 0;
vector<pii> coor;
vector<vector<bool>> visit;
vector<vector<int>> map;

int mv[8][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1} };

void bfs(int a, int b) {
    queue<pii> q;
    q.push({ a, b });
    visit[a][b] = true;

    while (!q.empty()) {       
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = x + mv[i][0];
            int ny = y + mv[i][1];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M || visit[nx][ny] || map[nx][ny] == 1) continue;
            if (map[nx][ny] <= map[x][y] + 1 && map[nx][ny] != 0) continue;

            if (map[nx][ny] > map[x][y] + 1 || map[nx][ny] == 0)
                map[nx][ny] = map[x][y] + 1;

            q.push({ nx, ny });
            visit[nx][ny] = true;
        }
    }
}

void Solution() {
    for (int i = 0; i < coor.size(); i++) {
        int x = coor[i].first, y = coor[i].second;
        bfs(x, y);

        fill(visit.begin(), visit.end(), vector<bool>(M, false));
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            ans = max(ans, map[i][j]);

    cout << ans - 1;  
}

void Input() {
    cin >> N >> M;

    map.resize(N, vector<int>(M));
    visit.resize(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];

            if (map[i][j] == 1) 
                coor.push_back({ i, j });
        }
            
}

void Solve() {
    Input();
    Solution();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solve();
    return 0;
}
