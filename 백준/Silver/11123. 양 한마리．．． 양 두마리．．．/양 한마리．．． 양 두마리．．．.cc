#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int H, W;
vector<vector<char>> map;
int mv[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

void bfs(int a, int b) {
    queue<pii> q;
    q.push({ a, b });
    map[a][b] = '.';

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + mv[i][0];
            int ny = y + mv[i][1];

            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (map[nx][ny] == '.') continue;

            map[nx][ny] = '.';
            q.push({ nx, ny });
        }
    }
}

void Solution() {
    int cnt = 0;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (map[i][j] != '.') {
                bfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
}

void Input() {
    int T;
    cin >> T;

    while (T--) {
        cin >> H >> W;
        map.resize(H, vector<char>(W));

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++)
                cin >> map[i][j];
        }
        Solution();
        map.clear();
    }   
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    return 0;
}