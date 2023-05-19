#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

int N, M, K, ans;
int mv[2][4] = { {-1, 1, 0, 0}, {0, 0, -1, 1} };
vector<vector<int>> map;
vector<pii> food;

void bfs(int a, int b) {
    int cnt = 1;
    queue<pii> q;
    q.push({ a, b });
    map[a][b] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0;i < 4;i++) {
            int nx = x + mv[0][i];
            int ny = y + mv[1][i];

            if (nx <= 0 || nx > N || ny <= 0 || ny > M) continue;

            if (map[nx][ny] == 1) {
                q.push({ nx, ny });
                map[nx][ny] = 0;
                cnt++;
            }
        }
    }
    ans = max(ans, cnt);
}

void Solution() {
    for (int i = 0;i < K;i++) {
        int x = food[i].first;
        int y = food[i].second;
        if (map[x][y] == 1) bfs(x, y);
    }
    cout << ans;
}

void Input() {
    cin >> N >> M >> K;
    map.resize(N + 1, vector<int>(M + 1, 0));
    food.resize(K);
    int r, c;

    for (int i = 0;i < K;i++) {
        cin >> r >> c;
        map[r][c] = 1;
        food[i] = { r, c };
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    Solution();
    return 0;
}