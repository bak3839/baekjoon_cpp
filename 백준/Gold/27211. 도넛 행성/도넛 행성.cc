#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<short>> map;

int N, M, res, cnt;
int mv1[4] = { -1, 1, 0, 0 };
int mv2[4] = { 0, 0 ,-1, 1 };

void bfs(int i, int j) {
    ++res;
    queue<pair<int, int>> q;
    q.push({ i, j });
    map[i][j] = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int j = 0; j < 4; j++) {
            int nx = x + mv1[j];
            int ny = y + mv2[j];

            if (0 > nx) nx = N - 1;
            if (N <= nx) nx = 0;
            if (0 > ny) ny = M - 1;
            if (M <= ny) ny = 0;

            if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                if (map[nx][ny] == 0) {
                    map[nx][ny] = 1;
                    q.push({ nx, ny });
                    cnt++;
                    if (cnt == N * M) break;
                }
            } 
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    short n;
    cin >> N >> M;
    map.resize(N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> n;
            map[i].push_back(n);
            if (n) ++cnt;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0) bfs(i, j);
        }
        if (cnt == N * M) break;
    }

    cout << res;
    return 0;
}