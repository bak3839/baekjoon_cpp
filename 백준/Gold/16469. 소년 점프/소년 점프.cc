#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

vector<vector<short>> map;
int cost[101][101][3];

int N, M, res = 100001, resCnt;
int mv1[4] = { 0, 0 ,-1, 1 };
int mv2[4] = { -1, 1, 0, 0 };

void bfs() {
    queue<vector<int>> q;
    int s, e;

    for (int i = 0; i < 3; i++) {
        cin >> s >> e;
        q.push({ s, e, i });
        cost[s][e][i] = 0;
    }

    while (!q.empty()) {
        int x = q.front()[0];
        int y = q.front()[1];
        int v = q.front()[2];
        q.pop();

        if (res < cost[x][y][v]) continue;

        for (int j = 0; j < 4; j++) {
            int nx = x + mv1[j];
            int ny = y + mv2[j];

            if (0 < nx && nx <= N && 0 < ny && ny <= M) {
                if (cost[nx][ny][v] == -1 && map[nx][ny] == 0) {
                    q.push({ nx, ny, v });

                    cost[nx][ny][v] = cost[x][y][v] + 1;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> N >> M;

    memset(cost, -1, sizeof(cost));
    map.resize(N + 1, vector<short>(M + 1));

    for (int i = 1; i <= N; i++) {
        cin >> s;
        for (int j = 1; j <= M; j++) {
            map[i][j] = s[j - 1] - 48;
        }
    }

    bfs();

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (cost[i][j][0] != -1 && cost[i][j][1] != -1 && cost[i][j][2] != -1) {
                int dist = max(max(cost[i][j][0], cost[i][j][1]), cost[i][j][2]);

                if (dist < res) {
                    res = dist;
                    resCnt = 1;
                }

                else if (dist == res) ++resCnt;
            }
        }
    }

    if (res == 100001) cout << -1;
    else cout << res << "\n" << resCnt;
    return 0;
}