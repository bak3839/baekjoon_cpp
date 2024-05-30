#include <iostream>
#include <vector>

using namespace std;

int R, C;
int mv[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
vector<vector<int>> map;
vector<vector<bool>> visit;

bool dfs(int r, int c, int cnt, int sum) {
    if (cnt == 3) {
        if (sum >= 2) return true;
        return false;
    }

    for (int i = 0; i < 4; i++) {
        int nr = r + mv[i][0];
        int nc = c + mv[i][1];

        if (nr < 0 || nc < 0 || nr > 4 || nc > 4 || map[nr][nc] == -1 || visit[nr][nc]) continue;

        visit[nr][nc] = true;
        if (dfs(nr, nc, cnt + 1, sum + map[nr][nc])) return true;
        visit[nr][nc] = false;
    }

    return false;
}

void Solution() {
    visit[R][C] = true;
    if (dfs(R, C, 0, 0)) cout << 1;
    else cout << 0;
}

void Input() {
    map.resize(5, vector<int>(5));
    visit.resize(5, vector<bool>(5, false));

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> map[i][j];

    cin >> R >> C;
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