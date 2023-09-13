#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int N, M, V, K, ans;
int mv[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
vector<vector<char>> map;

void bfs(int x, int y) {
    int v = 0, k = 0;
    queue<pii> q;
    q.push({ x, y });

    if (map[x][y] == 'v') v++;
    else if (map[x][y] == 'k') k++;
    map[x][y] = '#';

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0;i < 4;i++) {
            int nx = x + mv[i][0];
            int ny = y + mv[i][1];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            if (map[nx][ny] == '#') continue;
            else if (map[nx][ny] != '.')
                map[nx][ny] == 'v' ? v++ : k++;

            q.push({ nx, ny });
            map[nx][ny] = '#';
        }
    }

    if (k > v) V -= v;
    else K -= k;
}

void Solution() {
    for (int i = 0;i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == '#') continue;
            bfs(i, j);
        }
    }
    
    cout << K << " " << V;
}

void Input() {
    cin >> N >> M;

    map.resize(N, vector<char>(M));

    for (int i = 0;i < N;i++) {
        for (int j = 0;j < M;j++) {
            cin >> map[i][j];
            if (map[i][j] == 'v') V++;
            else if (map[i][j] == 'k') K++;
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