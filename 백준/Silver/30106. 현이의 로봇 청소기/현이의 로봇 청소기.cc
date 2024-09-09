#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;
using pii = pair<int, int>;

int N, M, K;
int mv[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

vector<vector<int>> map;
vector<vector<bool>> visit;

void bfs(int a, int b) {
    queue<pii> q;
    q.push({ a, b });
    visit[a][b] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        int height = map[x][y];

        for (int i = 0; i < 4; i++) {
            int nx = x + mv[i][0];
            int ny = y + mv[i][1];        

            if (nx < 0 || ny < 0 || nx >= N || ny >= M || visit[nx][ny]) continue;
            if (abs(height - map[nx][ny]) > K) continue;

            q.push({ nx, ny });
            visit[nx][ny] = true;
        }
    }
}

void Solution() {
    int ans = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            
            if (!visit[i][j]) {
                bfs(i, j);
                ans++;
            }
        }
    }

    cout << ans;
}

void Input() {
    cin >> N >> M >> K;

    map.resize(N, vector<int>(M));
    visit.resize(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
}

void Solve() {
    Input();
    Solution();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
    return 0;
}