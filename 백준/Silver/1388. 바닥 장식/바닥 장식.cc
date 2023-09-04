#include <iostream>
#include <vector>

using namespace std;

int N, M;
int mv[2] = { -1, 1 };
vector<vector<char>> map;

void dfs(int x, int y) {
    char now = map[x][y];
    map[x][y] = '*';

    if (now == '-') {
        for (int i = 0; i < 2; i++) {
            int ny = y + mv[i];

            if (ny < 0 || ny >= M || map[x][ny] != '-') continue;
            dfs(x, ny);
        }
    }
    else if(now == '|') {
        for (int i = 0; i < 2; i++) {
            int nx = x + mv[i];

            if (nx < 0 || nx >= N || map[nx][y] != '|') continue;
            dfs(nx, y);
        }
    }
}

void Solution() {
    int ans = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == '*') continue;
            dfs(i, j);
            ans++;
        }
    }

    cout << ans;
}

void Input() {
    cin >> N >> M;

    map.resize(N, vector<char>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
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
