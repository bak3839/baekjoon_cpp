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

            if (nx < 0 || ny < 0 || nx >= N || ny >= M || map[nx][ny] == '.') continue;

            map[nx][ny] = '.';
            q.push({ nx, ny });
        }
    }
}

void Solution() {
    int ans = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == '.') continue;

            BFS(i, j);
            ans++;
        }
    }

    cout << ans;
}

void Input() {
    cin >> N >> M;

    map.resize(N);

    for (int i = 0; i < N; i++)
        cin >> map[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solution();
    return 0;
}