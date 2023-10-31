#include <iostream>
#include <vector>

using namespace std;
using pii = pair<int, int>;

int mv[2][2] = { {1, 0}, {0, 1} };
int N, ans_min = 2100000, ans_max = -2100000;
vector<vector<char>> map;
vector<vector<bool>> visit;

void dfs(int x, int y, int sum, char mode) {
    int res = 0;

    if (x == N - 1 && y == N - 1) {
        if (mode == '*') res = sum * (map[x][y] - '0');
        else if (mode == '+') res = sum + (map[x][y] - '0');
        else if (mode == '-') res = sum - (map[x][y] - '0');

        ans_max = max(ans_max, res);
        ans_min = min(ans_min, res);
        return;
    }

    visit[x][y] = true;
    
    for (int i = 0; i < 2; i++) {
        int nx = x + mv[i][0];
        int ny = y + mv[i][1];

        if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
        if (visit[nx][ny]) continue;

        if (mode == '*') res = sum * (map[x][y] - '0');
        else if (mode == '+') res = sum + (map[x][y] - '0');
        else if (mode == '-') res = sum - (map[x][y] - '0');
        else res = sum;

        dfs(nx, ny, res, map[x][y]);
    }

    visit[x][y] = false;
}

void Solution() {
    dfs(0, 0, map[0][0] - '0', '0');
    cout << ans_max << " " << ans_min;
}

void Input() {
    cin >> N;

    map.resize(N, vector<char>(N));
    visit.resize(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> map[i][j];
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
