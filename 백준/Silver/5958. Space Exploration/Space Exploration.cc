#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int mv[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
vector<string> map;

void dfs(int x, int y) {
    map[x][y] = '.';

    for (int i = 0; i < 4; i++) {
        int nx = x + mv[i][0];
        int ny = y + mv[i][1];

        if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
        if (map[nx][ny] == '.') continue;

        dfs(nx, ny);
    }
}

void Solution() {
    int ans = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == '.') continue;

            dfs(i, j);
            ans++;
        }
    }

    cout << ans;
}

void Input() {
    cin >> N;

    map.resize(N);

    for (int i = 0; i < N; i++)
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