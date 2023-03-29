#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, n = 1;
vector<vector<char>> map;
vector<vector<int>> visit;

void input() {
    cin >> N >> M;
    map.resize(N, vector<char>(M));
    visit.resize(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
}

bool bfs(int a, int b) {
    bool pass = false;
    queue<pair<int, int>> q;
    q.push({ a, b });
    visit[a][b] = n;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        char now = map[x][y];

        if (now == 'L') y -= 1;
        else if (now == 'R') y += 1;
        else if (now == 'U') x -= 1;
        else if (now == 'D') x += 1;

        if (x < 0 || x >= N || y < 0 || y >= M) continue;

        if (visit[x][y] == 0) {
            q.push({ x, y });
            visit[x][y] = n;
        }

        else if (visit[x][y] == n) {
            pass = true;
            break;
        }

        else break;
    }
    return pass;
}

int solve() {
    int cnt = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] != 'x') {
                if (bfs(i, j)) cnt++;
                n++;
            }
        }
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    cout << solve();

    return 0;
}