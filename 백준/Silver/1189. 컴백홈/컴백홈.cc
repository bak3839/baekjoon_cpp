#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, K, ans;
int mv[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
vector<vector<char>> map;

void dfs(int x, int y, int cnt) {
    if (x == 0 && y == M - 1 && cnt == K) {
        ans++;
        return;
    }

    map[x][y] = 'T';

    for (int i = 0;i < 4; i++) {
        int nx = x + mv[i][0];
        int ny = y + mv[i][1];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (map[nx][ny] == 'T') continue;

        dfs(nx, ny, cnt + 1);
    }

    map[x][y] = '.';
}

void Solution() {
    dfs(N - 1, 0, 1);
    cout << ans;
}

void Input() {
    cin >> N >> M >> K;

    map.resize(N, vector<char>(M));

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