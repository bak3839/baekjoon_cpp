#include <iostream>
#include <vector>

using namespace std;

int N, M, ans;
int mv[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

vector<vector<int>> map;
vector<vector<bool>> visit;

void shape1(int r, int c){
    int sum = 0;
    sum = map[r][c] + map[r][c + 1] + map[r][c + 2] + map[r - 1][c + 1];
    ans = max(ans, sum);
}

void shape2(int r, int c){
    int sum = 0;
    sum = map[r][c] + map[r][c + 1] + map[r][c + 2] + map[r + 1][c + 1];
    ans = max(ans, sum);
}

void shape3(int r, int c){
    int sum = 0;
    sum = map[r][c] + map[r + 1][c] + map[r + 2][c] + map[r + 1][c + 1];
    ans = max(ans, sum);
}

void shape4(int r, int c){
    int sum = 0;
    sum = map[r][c] + map[r - 1][c + 1] + map[r][c + 1] + map[r + 1][c + 1];
    ans = max(ans, sum);
}

void dfs(int x, int y, int cnt, int sum) {
    if (cnt == 4) {
        ans = max(ans, sum);
        return;
    }

    visit[x][y] = true;

    for (int i = 0;i < 4;i++) {
        int nx = x + mv[i][0];
        int ny = y + mv[i][1];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (visit[nx][ny]) continue;

        dfs(nx, ny, cnt + 1, sum + map[x][y]);
    }

    visit[x][y] = false;
}

void Solution() {
    for (int i = 0;i < N;i++) {
        for (int j = 0;j < M;j++) {
            dfs(i, j, 0, 0);

            if (i - 1 >= 0 && j + 2 < M) shape1(i, j);
            if (j + 2 < M && i + 1 < N) shape2(i, j);
            if (i + 2 < N && j + 1 < M) shape3(i, j);
            if (i + 1 < N && i - 1 >= 0 && j + 1 < M) shape4(i, j);
        }
    }

    cout << ans;
}

void Input() {
    cin >> N >> M;

    map.resize(N, vector<int>(M));
    visit.resize(N, vector<bool>(M, false));

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