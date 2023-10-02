#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int R, C;
vector<vector<int>> map;
int mv[8][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };

void bfs(int x, int y) {
    queue<pii> q;
    q.push({ x, y });
    map[x][y] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = x + mv[i][0];
            int ny = y + mv[i][1];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (map[nx][ny] == 0) continue;

            q.push({ nx, ny });
            map[nx][ny] = 0;
        }
    }
}

void Solution() {
    int ans = 0;

    for (int i = 0;i < R;i++) {
        for (int j = 0;j < C;j++) {
            if (map[i][j] == 0) continue;

            bfs(i, j);
            ans++;
        }          
    }

    cout << ans;
}

void Input() {
    cin >> R >> C;

    map.resize(R, vector<int>(C));

    for (int i = 0;i < R;i++) {
        for (int j = 0;j < C;j++)
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