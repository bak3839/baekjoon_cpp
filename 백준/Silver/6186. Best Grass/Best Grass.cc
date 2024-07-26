#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int R, C;
vector<string> map;
int mv[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

void bfs(int r, int c) {
    queue<pii> q;
    q.push({ r, c });
    map[r][c] = '.';

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + mv[i][0];
            int ny = y + mv[i][1];

            if (nx < 0 || ny < 0 || nx >= R || ny >= C || map[nx][ny] == '.') continue;

            q.push({ nx, ny });
            map[nx][ny] = '.';
        }
    }
}

void Solution() {
    int ans = 0;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (map[i][j] == '#') {
                bfs(i, j);
                ans++;
            }
        }
    }

    cout << ans;
}

void Input() {
    cin >> R >> C;

    map.resize(R);

    for (int i = 0; i < R; i++)
        cin >> map[i];
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