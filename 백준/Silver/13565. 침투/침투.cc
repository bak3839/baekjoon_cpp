#include <iostream>
#include <vector>

using namespace std;


int N, M;
int mv[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
vector<string> map;

bool dfs(int x, int y) {
    if (x == N - 1) return true;

    map[x][y] = '1';

    for (int i = 0; i < 4; i++) {
        int nx = x + mv[i][0];
        int ny = y + mv[i][1];

        if (nx < 0 || ny < 0 || nx >= N || ny >= M || map[nx][ny] == '1') continue;

        if (dfs(nx, ny)) return true;
    }

    return false;
}

void Solution() {
    for (int i = 0; i < M; i++) {
        if (dfs(0, i)) {
            cout << "YES";
            return;
        }
    }

    cout << "NO";
}

void Input() {
    cin >> N >> M;

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