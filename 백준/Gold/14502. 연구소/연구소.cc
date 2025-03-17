#include <bits/stdc++.h>
#define map bak

using namespace std;
using pii = pair<int, int>;

int N, M, ans;
int map[8][8];
int mv[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
bool visited[8][8];
vector<pii> wall, virus;

int Spread() {
    int x, y, nx, ny, cnt = 0;
    
    queue<pii> q;

    for (int i = 0; i < virus.size(); i++) {
        x = virus[i].first, y = virus[i].second;
        q.push({ x, y });
        visited[x][y] = true;
    }

    while (q.size()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            nx = x + mv[i][0];
            ny = y + mv[i][1];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (visited[nx][ny] || map[nx][ny] != 0) continue;

            cnt++;
            q.push({ nx, ny });
            visited[nx][ny] = true;
        }
    }

    return (wall.size() - cnt - 3);
}

void Solve(int s, int cnt) {
    if (cnt == 3) {
        ans = max(ans, Spread());
        memset(visited, false, sizeof(visited));
        return;
    }

    for (int i = s; i < wall.size(); i++) {
        int x = wall[i].first, y = wall[i].second;

        map[x][y] = 1;
        Solve(i + 1, cnt + 1);
        map[x][y] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];

            if (map[i][j] == 0) wall.push_back({ i, j });
            else if (map[i][j] == 2) virus.push_back({ i, j });
        }
    }
    
    Solve(0, 0);
    cout << ans;
    return 0;
}
